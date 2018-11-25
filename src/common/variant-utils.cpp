// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/variant-utils.h"

#include "yasl/common/value.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/functiontemplate.h>
#include <script/interpreter/executioncontext.h>
#include <script/namespace.h>
#include <script/templateargumentdeduction.h>
#include <script/templatebuilder.h>

#include <map>
#include <memory>

namespace script
{

bool operator<(const script::Type & lhs, const script::Type & rhs)
{
  return lhs.data() < rhs.data();
}

} // namespace script

namespace yasl
{

struct VariantEngine
{
  std::map<script::Type, std::unique_ptr<VariantHandler>> handlers;
  std::map<int, script::Type> typemap;
};

VariantEngine* get_variant_engine()
{
  static VariantEngine vaeng = {};
  return &vaeng;
}

void register_variant_handler(VariantHandler *handler)
{
  auto *vaeng = get_variant_engine();
  vaeng->handlers[handler->script_type()] = std::unique_ptr<VariantHandler>(handler);
  vaeng->typemap[handler->qt_type()] = handler->script_type();
}

QVariant make_qvariant(const script::Value & v)
{
  switch (v.type().baseType().data())
  {
  case script::Type::Boolean:
    return QVariant(v.toBool());
  case script::Type::Char:
    return QVariant(v.toChar());
  case script::Type::Int:
    return QVariant(v.toInt());
  case script::Type::Float:
    return QVariant(v.toFloat());
  case script::Type::Double:
    return QVariant(v.toDouble());
  case script::Type::String:
    return QVariant(v.toString());
  default:
    break;
  }

  auto *vaeng = get_variant_engine();
  auto it = vaeng->handlers.find(v.type().baseType());
  if (it != vaeng->handlers.end())
  {
    return it->second->to_qvariant(v);
  }
  else
  {
    auto typeinfo = TypeInfo::get(v.engine(), v.type());
    return QVariant::fromValue(yasl::Value{ typeinfo, v });
  }
}

script::Value get_variant_value(script::Engine *e, const QVariant & v)
{
  if (v.type() == qMetaTypeId<yasl::Value>())
    return v.value<yasl::Value>().release();

  switch (v.type())
  {
  case QMetaType::Bool:
    return e->newBool(v.toBool());
  case QMetaType::Char:
    return e->newChar(v.value<char>());
  case QMetaType::Int:
    return e->newInt(v.toInt());
  case QMetaType::Float:
    return e->newFloat(v.toFloat());
  case QMetaType::Double:
    return e->newDouble(v.toDouble());
  case QMetaType::QString:
    return e->newString(v.toString());
  default:
    break;
  }

  auto *vaeng = get_variant_engine();
  script::Type t = vaeng->typemap.at(v.type());
  return vaeng->handlers[t]->from_qvariant(e, v);
}

script::Type get_variant_value_type(const QVariant & v)
{
  if (v.userType() == qMetaTypeId<yasl::Value>())
    return v.value<yasl::Value>().get().type();

  switch (v.userType())
  {
  case QMetaType::Bool:
    return script::Type::Boolean;
  case QMetaType::Char:
    return script::Type::Char;
  case QMetaType::Int:
    return script::Type::Int;
  case QMetaType::Float:
    return script::Type::Float;
  case QMetaType::Double:
    return script::Type::Double;
  case QMetaType::QString:
    return script::Type::String;
  default:
    break;
  }

  auto *vaeng = get_variant_engine();
  return vaeng->typemap.at(v.userType());
}



static script::Value variant_value_callback(script::FunctionCall *c)
{
  using namespace script;
  const Type & rt = c->callee().returnType();
  QVariant v = c->thisObject().toVariant();
  if (get_variant_value_type(v) == rt)
    return get_variant_value(c->engine(), v);
  else
    return c->engine()->construct(rt, {});
}

static void variant_value_deduce(script::TemplateArgumentDeduction &deduc, const script::FunctionTemplate & variant_value, const std::vector<script::TemplateArgument> & targs, const std::vector<script::Type> & itypes)
{
  using namespace script;

  if (targs.size() != 1)
    return deduc.fail();

  /// TODO: check targs.front() is copy constructible
}

static void variant_value_substitute(script::FunctionBuilder & builder, script::FunctionTemplate variant_value, const std::vector<script::TemplateArgument> & targs)
{
  using namespace script;

  builder.returns(targs.front().type.baseType());
  builder.setConst();
}

static std::pair<script::NativeFunctionSignature, std::shared_ptr<script::UserData>> variant_value_instantitate(script::FunctionTemplate variant_value, script::Function instance)
{
  using namespace script;

  return { variant_value_callback, nullptr };
}



static script::Value variant_fromvalue_callback(script::FunctionCall *c)
{
  using namespace script;
  return c->engine()->construct(Type::QVariant, [&](script::Value & val) {
    val.setVariant(make_qvariant(c->arg(0)));
  });
}

static void variant_fromvalue_deduce(script::TemplateArgumentDeduction &deduc, const script::FunctionTemplate & variant_fromvalue, const std::vector<script::TemplateArgument> & targs, const std::vector<script::Type> & itypes)
{
  using namespace script;

  if (targs.size() == 1)
    return;

  if (itypes.size() != 1)
    return deduc.fail();

  deduc.record_deduction(0, TemplateArgument{ itypes.front() });
}

static void variant_fromvalue_substitute(script::FunctionBuilder & builder, script::FunctionTemplate variant_fromvalue, const std::vector<script::TemplateArgument> & targs)
{
  using namespace script;

  builder.setStatic();
  builder.returns(Type::QVariant);
  builder.params(Type::cref(targs.front().type));
}

static std::pair<script::NativeFunctionSignature, std::shared_ptr<script::UserData>> variant_fromvalue_instantitate(script::FunctionTemplate variant_fromvalue, script::Function instance)
{
  using namespace script;

  return { variant_fromvalue_callback, nullptr };
}



static script::Value variant_type_callback(script::FunctionCall *c)
{
  return c->engine()->newInt(get_variant_value_type(c->thisObject().toVariant()).data());
}


void complete_variant_class(script::Engine *e)
{
  using namespace script;
  
  Class variant = e->getClass(script::Type::QVariant);

  // T value() const; 
  {
    std::vector<TemplateParameter> params;
    params.push_back(TemplateParameter{ TemplateParameter::TypeParameter{}, "T" });

    FunctionTemplate variant_value = Symbol{ variant }.newFunctionTemplate("value")
      .setParams(std::move(params))
      .setScope(Scope{ variant })
      .deduce(variant_value_deduce).substitute(variant_value_substitute).instantiate(variant_value_instantitate)
      .get();
  }

  // static Variant fromValue(const T &);
  {
    std::vector<TemplateParameter> params;
    params.push_back(TemplateParameter{ TemplateParameter::TypeParameter{}, "T" });

    FunctionTemplate variant_fromvalue = Symbol{ variant }.newFunctionTemplate("fromValue")
      .setParams(std::move(params))
      .setScope(Scope{ variant })
      .deduce(variant_fromvalue_deduce).substitute(variant_fromvalue_substitute).instantiate(variant_fromvalue_instantitate)
      .get();
  }

  // int type() const;
  variant.newMethod("type", variant_type_callback)
    .setConst()
    .returns(Type::Int)
    .create();
}

} // namespace yasl

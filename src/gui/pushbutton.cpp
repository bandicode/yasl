// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/pushbutton.h"

#include "yasl/binding/qclass.h"
#include "yasl/binding/qsignal.h"

#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/interpreter/executioncontext.h>
#include <script/value.h>

namespace callbacks
{

static script::Value new_pushbutton(script::FunctionCall *c)
{
  using namespace script;
  Type type = c->callee().returnType().baseType();
  Value v = c->engine()->construct(type, {});
  return v;
}


static script::Value new_pushbutton_parent(script::FunctionCall *c)
{
  using namespace binding;
  QPushButton *object = new QPushButton(value_cast<QWidget*>(c->arg(0)));
  return make_object(c->engine(), c->callee().returnType().baseType(), object);
}

static script::Value new_pushbutton_text(script::FunctionCall *c)
{
  using namespace binding;
  QPushButton *object = new QPushButton(value_cast<const QString &>(c->arg(0)));
  return make_object(c->engine(), c->callee().returnType().baseType(), object);
}

static script::Value new_pushbutton_text_parent(script::FunctionCall *c)
{
  using namespace binding;
  QPushButton *object = new QPushButton(value_cast<const QString &>(c->arg(0)), value_cast<QWidget*>(c->arg(1)));
  return make_object(c->engine(), c->callee().returnType().baseType(), object);
}

} // namespace callbacks


void register_qpushbutton(script::Namespace n)
{
  using namespace script;

  Class widget = n.engine()->getClass(script::Type::QWidget);

  Class pushbutton = n.newClass(ClassBuilder::New("PushButton").setId(Type::QPushButton).setParent(widget));
  Type pushbutton_type = pushbutton.id();

  auto qpushbutton = binding::QClass<QPushButton>{ pushbutton };
  qpushbutton.ctors().add_default();
  qpushbutton.ctors().add<QWidget*>();
  qpushbutton.ctors().add<const QString &>();
  qpushbutton.ctors().add<const QString &, QWidget*>();
  qpushbutton.add_dtor();

  /* Inherited from QAbstractButton */
  auto qabstractbutton = binding::QClass<QAbstractButton>{ pushbutton };
  // bool autoExclusive() const
  qabstractbutton.add_fun<bool, &QAbstractButton::autoExclusive>("autoExclusive");
  // bool autoRepeat() const
  qabstractbutton.add_fun<bool, &QAbstractButton::autoRepeat>("autoRepeat");
  // int autoRepeatDelay() const
  qabstractbutton.add_fun<int, &QAbstractButton::autoRepeatDelay>("autoRepeatDelay");
  // int autoRepeatInterval() const
  qabstractbutton.add_fun<int, &QAbstractButton::autoRepeatInterval>("autoRepeatInterval");
  // QButtonGroup * group() const
  // QIcon icon() const
  // QSize iconSize() const
  // bool isCheckable() const
  qabstractbutton.add_fun<bool, &QAbstractButton::isCheckable>("isCheckable");
  // bool isChecked() const
  qabstractbutton.add_fun<bool, &QAbstractButton::isChecked>("isChecked");
  // bool isDown() const
  qabstractbutton.add_fun<bool, &QAbstractButton::isDown>("isDown");
  // void setAutoExclusive(bool)
  qabstractbutton.add_void_fun<bool, &QAbstractButton::setAutoExclusive>("setAutoExclusive");
  // void setAutoRepeat(bool)
  qabstractbutton.add_void_fun<bool, &QAbstractButton::setAutoRepeat>("setAutoRepeat");
  // void setAutoRepeatDelay(int)
  qabstractbutton.add_void_fun<int, &QAbstractButton::setAutoRepeatDelay>("setAutoRepeatDelay");
  // void setAutoRepeatInterval(int)
  qabstractbutton.add_void_fun<int, &QAbstractButton::setAutoRepeatInterval>("setAutoRepeatInterval");
  // void setCheckable(bool)
  qabstractbutton.add_void_fun<bool, &QAbstractButton::setCheckable>("setCheckable");
  // void setDown(bool)
  qabstractbutton.add_void_fun<bool, &QAbstractButton::setDown>("setDown");
  // void setIcon(const QIcon &icon)
  // void setShortcut(const QKeySequence &key)
  // void setText(const QString &text)
  qabstractbutton.add_void_fun<const QString &, &QAbstractButton::setText>("setText");
  // QKeySequence shortcut() const
  // QString text() const
  qabstractbutton.add_fun<QString, &QAbstractButton::text>("text");

  /* QPushButton members */
  // bool autoDefault() const
  qpushbutton.add_fun<bool, &QPushButton::autoDefault>("autoDefault");
  // bool isDefault() const
  qpushbutton.add_fun<bool, &QPushButton::isDefault>("isDefault");
  // bool isFlat() const
  qpushbutton.add_fun<bool, &QPushButton::isFlat>("isFlat");
  // QMenu * menu() const
  // void setAutoDefault(bool)
  qpushbutton.add_void_fun<bool, &QPushButton::setAutoDefault>("setAutoDefault");
  // void setDefault(bool)
  qpushbutton.add_void_fun<bool, &QPushButton::setDefault>("setDefault");
  // void setFlat(bool)
  qpushbutton.add_void_fun<bool, &QPushButton::setFlat>("setFlat");
  // void setMenu(QMenu *menu)

  binding::QSignal qpushbutton_signals{ pushbutton, &QPushButton::staticMetaObject };
  qpushbutton_signals.add("clicked", Q_SIGNAL("clicked()"));

  n.Function("newPushButton", callbacks::new_pushbutton)
    .returns(Type::ref(pushbutton_type))
    .create();

  n.Function("newPushButton", callbacks::new_pushbutton_parent)
    .returns(Type::ref(pushbutton_type))
    .params(binding::make_type<QWidget*>())
    .create();

  n.Function("newPushButton", callbacks::new_pushbutton_text)
    .returns(Type::ref(pushbutton_type))
    .params(binding::make_type<const QString &>())
    .create();

  n.Function("newPushButton", callbacks::new_pushbutton_text_parent)
    .returns(Type::ref(pushbutton_type))
    .params(binding::make_type<const QString &>(), binding::make_type<QWidget*>())
    .create();

  n.engine()->registerQtType(&QPushButton::staticMetaObject, pushbutton_type);
}


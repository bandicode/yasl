// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_OPERATOR_WRAPPER_H
#define YASL_BINDING_OPERATOR_WRAPPER_H

#include "yasl/binding/utils.h"

#include <script/interpreter/executioncontext.h>

namespace binding
{

template<typename LHS, typename RHS>
script::Value add_wrapper(script::FunctionCall *c)
{
  return make_value(value_cast<LHS>(c->arg(0)) + value_cast<RHS>(c->arg(1)), c->engine());
}

template<typename LHS, typename RHS>
script::Value sub_wrapper(script::FunctionCall *c)
{
  return make_value(value_cast<LHS>(c->arg(0)) - value_cast<RHS>(c->arg(1)), c->engine());
}

template<typename LHS, typename RHS>
script::Value mul_wrapper(script::FunctionCall *c)
{
  return make_value(value_cast<LHS>(c->arg(0)) * value_cast<RHS>(c->arg(1)), c->engine());
}

template<typename LHS, typename RHS>
script::Value div_wrapper(script::FunctionCall *c)
{
  return make_value(value_cast<LHS>(c->arg(0)) / value_cast<RHS>(c->arg(1)), c->engine());
}

template<typename LHS, typename RHS>
script::Value assign_wrapper(script::FunctionCall *c)
{
  value_cast<LHS>(c->arg(0)) = value_cast<RHS>(c->arg(1));
  return c->arg(0);
}

template<typename LHS, typename RHS>
script::Value add_assign_wrapper(script::FunctionCall *c)
{
  value_cast<LHS>(c->arg(0)) += value_cast<RHS>(c->arg(1));
  return c->arg(0);
}

template<typename LHS, typename RHS>
script::Value sub_assign_wrapper(script::FunctionCall *c)
{
  value_cast<LHS>(c->arg(0)) -= value_cast<RHS>(c->arg(1));
  return c->arg(0);
}

template<typename LHS, typename RHS>
script::Value mul_assign_wrapper(script::FunctionCall *c)
{
  value_cast<LHS>(c->arg(0)) *= value_cast<RHS>(c->arg(1));
  return c->arg(0);
}

template<typename LHS, typename RHS>
script::Value div_assign_wrapper(script::FunctionCall *c)
{
  value_cast<LHS>(c->arg(0)) /= value_cast<RHS>(c->arg(1));
  return c->arg(0);
}

template<typename LHS, typename RHS>
script::Value eq_wrapper(script::FunctionCall *c)
{
  return c->engine()->newBool(value_cast<LHS>(c->arg(0)) == value_cast<RHS>(c->arg(1)));
}

template<typename LHS, typename RHS>
script::Value neq_wrapper(script::FunctionCall *c)
{
  return c->engine()->newBool(value_cast<LHS>(c->arg(0)) != value_cast<RHS>(c->arg(1)));
}

template<typename LHS, typename RHS>
script::Value less_wrapper(script::FunctionCall *c)
{
  return c->engine()->newBool(value_cast<LHS>(c->arg(0)) < value_cast<RHS>(c->arg(1)));
}

template<typename LHS, typename RHS>
script::Value leq_wrapper(script::FunctionCall *c)
{
  return c->engine()->newBool(value_cast<LHS>(c->arg(0)) <= value_cast<RHS>(c->arg(1)));
}

template<typename LHS, typename RHS>
script::Value greater_wrapper(script::FunctionCall *c)
{
  return c->engine()->newBool(value_cast<LHS>(c->arg(0)) > value_cast<RHS>(c->arg(1)));
}

template<typename LHS, typename RHS>
script::Value geq_wrapper(script::FunctionCall *c)
{
  return c->engine()->newBool(value_cast<LHS>(c->arg(0)) >= value_cast<RHS>(c->arg(1)));
}

template<typename LHS, typename RHS>
script::Value and_wrapper(script::FunctionCall *c)
{
  return make_value(value_cast<LHS>(c->arg(0)) & value_cast<RHS>(c->arg(1)), c->engine());
}

template<typename LHS, typename RHS>
script::Value or_wrapper(script::FunctionCall *c)
{
  return make_value(value_cast<LHS>(c->arg(0)) | value_cast<RHS>(c->arg(1)), c->engine());
}

template<typename LHS, typename RHS>
script::Value and_assign_wrapper(script::FunctionCall *c)
{
  value_cast<LHS>(c->arg(0)) &= value_cast<RHS>(c->arg(1));
  return c->arg(0);
}

template<typename LHS, typename RHS>
script::Value or_assign_wrapper(script::FunctionCall *c)
{
  value_cast<LHS>(c->arg(0)) |= value_cast<RHS>(c->arg(1));
  return c->arg(0);
}

template<typename ReturnType, typename LHS, typename RHS>
script::Value subscript_wrapper(script::FunctionCall *c)
{
  return make_value<ReturnType>(value_cast<LHS>(c->arg(0))[value_cast<RHS>(c->arg(1))], c->engine());
}

} // namespace binding

#endif // YASL_BINDING_OPERATOR_WRAPPER_H

// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_QEVENT_BINDER_H
#define YASL_CORE_QEVENT_BINDER_H

#include "yasl/binding/class.h"
#include "yasl/core/qevent-binding.h"


namespace callbacks
{
script::Value qevent_dtor(script::FunctionCall *c);
} // namespace callbacks


namespace binding
{

template<typename T, typename...Args>
struct constructor_wrapper_event_t;

template<typename T>
struct constructor_wrapper_event_t<T> {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    self.impl()->data.ptr = new T();
    return self;
  }
};

template<typename T, typename A1>
struct constructor_wrapper_event_t<T, A1> {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    self.impl()->data.ptr = new T(value_cast<A1>(c->arg(1)));
    return self;
  }
};

template<typename T, typename A1, typename A2>
struct constructor_wrapper_event_t<T, A1, A2> {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    self.impl()->data.ptr = new T(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)));
    return self;
  }
};

template<typename T, typename A1, typename A2, typename A3>
struct constructor_wrapper_event_t<T, A1, A2, A3> {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    self.impl()->data.ptr = new T(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)));
    return self;
  }
};

template<typename T, typename A1, typename A2, typename A3, typename A4>
struct constructor_wrapper_event_t<T, A1, A2, A3, A4> {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    self.impl()->data.ptr = new T(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)));
    return self;
  }
};

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5>
struct constructor_wrapper_event_t<T, A1, A2, A3, A4, A5> {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    self.impl()->data.ptr = new T(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)));
    return self;
  }
};

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
struct constructor_wrapper_event_t<T, A1, A2, A3, A4, A5, A6> {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    self.impl()->data.ptr = new T(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)), value_cast<A6>(c->arg(6)));
    return self;
  }
};


template<typename T>
class ClassBinder<T, qevent_tag> : public GenericClassBinder<T>
{
public:

  ClassBinder(const script::Class c)
    : GenericClassBinder<T>(c)
  { }

public:

  /****************************************************************
  Constructors
  ****************************************************************/

  script::ConstructorBuilder default_ctor()
  {
    return class_.Constructor(constructor_wrapper_small_object_t<T>::wrap);
  }

  script::ConstructorBuilder copy_ctor()
  {
    return class_.Constructor(constructor_wrapper_small_object_t<T, const T&>::wrap)
      .params(script::Type::cref(make_type<T>()));
  }

  template<typename A1>
  script::ConstructorBuilder ctor()
  {
    return class_.Constructor(constructor_wrapper_event_t<T, A1>::wrap)
      .params(make_type<A1>());
  }

  template<typename A1, typename A2>
  script::ConstructorBuilder ctor()
  {
    return class_.Constructor(constructor_wrapper_event_t<T, A1, A2>::wrap)
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename A1, typename A2, typename A3>
  script::ConstructorBuilder ctor()
  {
    return class_.Constructor(constructor_wrapper_event_t<T, A1, A2, A3>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  template<typename A1, typename A2, typename A3, typename A4>
  script::ConstructorBuilder ctor()
  {
    return class_.Constructor(constructor_wrapper_event_t<T, A1, A2, A3, A4>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5>
  script::ConstructorBuilder ctor()
  {
    return class_.Constructor(constructor_wrapper_event_t<T, A1, A2, A3, A4, A5>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
  script::ConstructorBuilder ctor()
  {
    return class_.Constructor(constructor_wrapper_event_t<T, A1, A2, A3, A4, A5, A6>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>());
  }

  /****************************************************************
  Destructor
  ****************************************************************/

  script::DestructorBuilder dtor()
  {
    return class_.Destructor(callbacks::qevent_dtor);
  }

};

} // namespace binding

#endif // YASL_CORE_QEVENT_BINDER_H

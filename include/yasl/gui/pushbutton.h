// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_PUSHBUTTON_H
#define YASL_GUI_PUSHBUTTON_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QPushButton>

namespace binding {
template<> struct make_type_t<QPushButton> { inline static script::Type get() { return script::Type::QPushButton; } };
template<> struct tag_resolver<QPushButton> { typedef qobject_tag tag_type; };
} // namespace binding

#endif // YASL_GUI_PUSHBUTTON_H

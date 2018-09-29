// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_LAYOUT_H
#define YASL_WIDGETS_LAYOUT_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QLayout>

namespace binding {
template<> struct make_type_t<QLayout> { inline static script::Type get() { return script::Type::QLayout; } };
template<> struct tag_resolver<QLayout> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QLayout*> { inline static script::Type get() { return script::Type::QLayoutStar; } };
template<> struct make_type_t<QLayout::SizeConstraint> { inline static script::Type get() { return script::Type::QLayoutSizeConstraint; } };
} // namespace binding

#endif // YASL_WIDGETS_LAYOUT_H
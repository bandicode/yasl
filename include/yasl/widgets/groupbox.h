// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_GROUPBOX_H
#define YASL_WIDGETS_GROUPBOX_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QGroupBox>

namespace binding {
template<> struct make_type_t<QGroupBox> { inline static script::Type get() { return script::Type::QGroupBox; } };
template<> struct tag_resolver<QGroupBox> { typedef qobject_tag tag_type; };
} // namespace binding

#endif // YASL_WIDGETS_GROUPBOX_H
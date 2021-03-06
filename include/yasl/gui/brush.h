// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_BRUSH_H
#define YASL_GUI_BRUSH_H

#include "yasl/common/types.h"

#include <QBrush>

namespace script {
template<> struct make_type_helper<QBrush> { inline static script::Type get() { return script::Type::QBrush; } };
template<> struct make_type_helper<QConicalGradient> { inline static script::Type get() { return script::Type::QConicalGradient; } };
template<> struct make_type_helper<QGradient> { inline static script::Type get() { return script::Type::QGradient; } };
template<> struct make_type_helper<QGradient::CoordinateMode> { inline static script::Type get() { return script::Type::QGradientCoordinateMode; } };
template<> struct make_type_helper<QGradient::InterpolationMode> { inline static script::Type get() { return script::Type::QGradientInterpolationMode; } };
template<> struct make_type_helper<QGradient::Spread> { inline static script::Type get() { return script::Type::QGradientSpread; } };
template<> struct make_type_helper<QGradient::Type> { inline static script::Type get() { return script::Type::QGradientType; } };
template<> struct make_type_helper<QLinearGradient> { inline static script::Type get() { return script::Type::QLinearGradient; } };
template<> struct make_type_helper<QRadialGradient> { inline static script::Type get() { return script::Type::QRadialGradient; } };
} // namespace script

#endif // YASL_GUI_BRUSH_H

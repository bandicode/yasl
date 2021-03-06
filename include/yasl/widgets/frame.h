// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_FRAME_H
#define YASL_WIDGETS_FRAME_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QFrame>

namespace script {
template<> struct make_type_helper<QFrame> { inline static script::Type get() { return script::Type::QFrame; } };
namespace details { template<> struct tag_resolver<QFrame> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QFrame::Shadow> { inline static script::Type get() { return script::Type::QFrameShadow; } };
template<> struct make_type_helper<QFrame::Shape> { inline static script::Type get() { return script::Type::QFrameShape; } };
template<> struct make_type_helper<QFrame::StyleMask> { inline static script::Type get() { return script::Type::QFrameStyleMask; } };
} // namespace script

#endif // YASL_WIDGETS_FRAME_H

// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_CURSOR_H
#define YASL_GUI_CURSOR_H

#include "yasl/common/types.h"

#include <QCursor>

namespace script {
template<> struct make_type_helper<QCursor> { inline static script::Type get() { return script::Type::QCursor; } };
} // namespace script

#endif // YASL_GUI_CURSOR_H

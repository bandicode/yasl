// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_MIMETYPE_H
#define YASL_CORE_MIMETYPE_H

#include "yasl/common/types.h"

#include <QMimeType>

namespace script {
template<> struct make_type_helper<QMimeType> { inline static script::Type get() { return script::Type::QMimeType; } };
} // namespace script

#endif // YASL_CORE_MIMETYPE_H

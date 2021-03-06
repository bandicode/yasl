// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_DATASTREAM_H
#define YASL_CORE_DATASTREAM_H

#include "yasl/common/types.h"

#include <QDataStream>

namespace script {
template<> struct make_type_helper<QDataStream> { inline static script::Type get() { return script::Type::QDataStream; } };
template<> struct make_type_helper<QDataStream::ByteOrder> { inline static script::Type get() { return script::Type::QDataStreamByteOrder; } };
template<> struct make_type_helper<QDataStream::FloatingPointPrecision> { inline static script::Type get() { return script::Type::QDataStreamFloatingPointPrecision; } };
template<> struct make_type_helper<QDataStream::Status> { inline static script::Type get() { return script::Type::QDataStreamStatus; } };
template<> struct make_type_helper<QDataStream::Version> { inline static script::Type get() { return script::Type::QDataStreamVersion; } };
} // namespace script

#endif // YASL_CORE_DATASTREAM_H

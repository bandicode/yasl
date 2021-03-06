// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_LOCALE_H
#define YASL_CORE_LOCALE_H

#include "yasl/common/proxy.h"
#include "yasl/common/types.h"

#include <QLocale>

namespace script {
template<> struct make_type_helper<Proxy<QLocale>> { inline static script::Type get() { return script::Type::ProxyQLocale; } };
template<> struct make_type_helper<QList<QLocale>> { inline static script::Type get() { return script::Type::QListQLocale; } };
template<> struct make_type_helper<QList<QLocale>::const_iterator> { inline static script::Type get() { return script::Type::QListQLocaleConstIterator; } };
template<> struct make_type_helper<QList<QLocale>::iterator> { inline static script::Type get() { return script::Type::QListQLocaleIterator; } };
template<> struct make_type_helper<QLocale> { inline static script::Type get() { return script::Type::QLocale; } };
template<> struct make_type_helper<QLocale::Country> { inline static script::Type get() { return script::Type::QLocaleCountry; } };
template<> struct make_type_helper<QLocale::CurrencySymbolFormat> { inline static script::Type get() { return script::Type::QLocaleCurrencySymbolFormat; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
template<> struct make_type_helper<QLocale::DataSizeFormat> { inline static script::Type get() { return script::Type::QLocaleDataSizeFormat; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
template<> struct make_type_helper<QLocale::FloatingPointPrecisionOption> { inline static script::Type get() { return script::Type::QLocaleFloatingPointPrecisionOption; } };
#endif
template<> struct make_type_helper<QLocale::FormatType> { inline static script::Type get() { return script::Type::QLocaleFormatType; } };
template<> struct make_type_helper<QLocale::Language> { inline static script::Type get() { return script::Type::QLocaleLanguage; } };
template<> struct make_type_helper<QLocale::MeasurementSystem> { inline static script::Type get() { return script::Type::QLocaleMeasurementSystem; } };
template<> struct make_type_helper<QLocale::NumberOption> { inline static script::Type get() { return script::Type::QLocaleNumberOption; } };
template<> struct make_type_helper<QLocale::NumberOptions> { inline static script::Type get() { return script::Type::QLocaleNumberOptions; } };
template<> struct make_type_helper<QLocale::QuotationStyle> { inline static script::Type get() { return script::Type::QLocaleQuotationStyle; } };
template<> struct make_type_helper<QLocale::Script> { inline static script::Type get() { return script::Type::QLocaleScript; } };
} // namespace script

#endif // YASL_CORE_LOCALE_H

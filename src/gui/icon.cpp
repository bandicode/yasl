// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/icon.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/macros.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/size.h"
#include "yasl/core/string.h"

#include "yasl/gui/painter.h"
#include "yasl/gui/pixmap.h"
#include "yasl/gui/window.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/enumbuilder.h>
#include <script/namespace.h>

#include <QDebug>

static void register_icon_mode_enum(script::Class icon)
{
  using namespace script;

  Enum mode = icon.Enum("Mode").setId(script::Type::QIconMode).get();

  mode.addValue("Active", QIcon::Active);
  mode.addValue("Disabled", QIcon::Disabled);
  mode.addValue("Normal", QIcon::Normal);
  mode.addValue("Selected", QIcon::Selected);
}

static void register_icon_state_enum(script::Class icon)
{
  using namespace script;

  Enum state = icon.Enum("State").setId(script::Type::QIconState).get();

  state.addValue("Off", QIcon::Off);
  state.addValue("On", QIcon::On);
}

static void register_icon_class(script::Namespace ns)
{
  using namespace script;

  Class icon = ns.Class("Icon").setId(script::Type::QIcon).get();

  register_icon_mode_enum(icon);
  register_icon_state_enum(icon);
  binding::Class<QIcon> binder{ icon };

  // ~QIcon();
  binder.add_dtor();
  // QIcon();
  binder.ctors().add_default();
  // QIcon(const QPixmap &);
  binder.ctors().add<const QPixmap &>();
  // QIcon(const QIcon &);
  binder.ctors().add<const QIcon &>();
  // QIcon(QIcon &&);
  binder.ctors().add<QIcon &&>();
  // QIcon(const QString &);
  binder.ctors().add<const QString &>();
  // QIcon(QIconEngine *);
  /// ignore: binder.ctors().add<QIconEngine *>();
  // QIcon & operator=(const QIcon &);
  binder.operators().assign<const QIcon &>();
  // QIcon & operator=(QIcon &&);
  binder.operators().assign<QIcon &&>();
  // void swap(QIcon &);
  binder.add_void_fun<QIcon &, &QIcon::swap>("swap");
  // QPixmap pixmap(const QSize &, QIcon::Mode, QIcon::State) const;
  binder.add_fun<QPixmap, const QSize &, QIcon::Mode, QIcon::State, &QIcon::pixmap>("pixmap");
  // QPixmap pixmap(int, int, QIcon::Mode, QIcon::State) const;
  binder.add_fun<QPixmap, int, int, QIcon::Mode, QIcon::State, &QIcon::pixmap>("pixmap");
  // QPixmap pixmap(int, QIcon::Mode, QIcon::State) const;
  binder.add_fun<QPixmap, int, QIcon::Mode, QIcon::State, &QIcon::pixmap>("pixmap");
  // QPixmap pixmap(QWindow *, const QSize &, QIcon::Mode, QIcon::State) const;
  binder.add_fun<QPixmap, QWindow *, const QSize &, QIcon::Mode, QIcon::State, &QIcon::pixmap>("pixmap");
  // QSize actualSize(const QSize &, QIcon::Mode, QIcon::State) const;
  binder.add_fun<QSize, const QSize &, QIcon::Mode, QIcon::State, &QIcon::actualSize>("actualSize");
  // QSize actualSize(QWindow *, const QSize &, QIcon::Mode, QIcon::State) const;
  binder.add_fun<QSize, QWindow *, const QSize &, QIcon::Mode, QIcon::State, &QIcon::actualSize>("actualSize");
  // QString name() const;
  binder.add_fun<QString, &QIcon::name>("name");
  // void paint(QPainter *, const QRect &, Qt::Alignment, QIcon::Mode, QIcon::State) const;
  /// TODO: binder.add_const_void_fun<QPainter *, const QRect &, Qt::Alignment, QIcon::Mode, QIcon::State, &QIcon::paint>("paint");
  // void paint(QPainter *, int, int, int, int, Qt::Alignment, QIcon::Mode, QIcon::State) const;
  /// TODO: binder.add_const_void_fun<QPainter *, int, int, int, int, Qt::Alignment, QIcon::Mode, QIcon::State, &QIcon::paint>("paint");
  // bool isNull() const;
  binder.add_fun<bool, &QIcon::isNull>("isNull");
  // bool isDetached() const;
  binder.add_fun<bool, &QIcon::isDetached>("isDetached");
  // void detach();
  binder.add_void_fun<&QIcon::detach>("detach");
  // qint64 cacheKey() const;
  binder.add_fun<qint64, &QIcon::cacheKey>("cacheKey");
  // void addPixmap(const QPixmap &, QIcon::Mode, QIcon::State);
  binder.add_void_fun<const QPixmap &, QIcon::Mode, QIcon::State, &QIcon::addPixmap>("addPixmap");
  // void addFile(const QString &, const QSize &, QIcon::Mode, QIcon::State);
  binder.add_void_fun<const QString &, const QSize &, QIcon::Mode, QIcon::State, &QIcon::addFile>("addFile");
  // QList<QSize> availableSizes(QIcon::Mode, QIcon::State) const;
  binder.add_fun<QList<QSize>, QIcon::Mode, QIcon::State, &QIcon::availableSizes>("availableSizes");
  // void setIsMask(bool);
  binder.add_void_fun<bool, &QIcon::setIsMask>("setIsMask");
  // bool isMask() const;
  binder.add_fun<bool, &QIcon::isMask>("isMask");
  // static QIcon fromTheme(const QString &);
  binder.add_static<QIcon, const QString &, &QIcon::fromTheme>("fromTheme");
  // static QIcon fromTheme(const QString &, const QIcon &);
  binder.add_static<QIcon, const QString &, const QIcon &, &QIcon::fromTheme>("fromTheme");
  // static bool hasThemeIcon(const QString &);
  binder.add_static<bool, const QString &, &QIcon::hasThemeIcon>("hasThemeIcon");
  // static QStringList themeSearchPaths();
  binder.add_static<QStringList, &QIcon::themeSearchPaths>("themeSearchPaths");
  // static void setThemeSearchPaths(const QStringList &);
  binder.add_static_void_fun<const QStringList &, &QIcon::setThemeSearchPaths>("setThemeSearchPaths");
  // static QString themeName();
  binder.add_static<QString, &QIcon::themeName>("themeName");
  // static void setThemeName(const QString &);
  binder.add_static_void_fun<const QString &, &QIcon::setThemeName>("setThemeName");
}

void register_icon_file(script::Namespace root)
{
  using namespace script;

  register_icon_class(root);
  binding::Namespace binder{ root };

  // void swap(QIcon &, QIcon &);
  binder.add_void_fun<QIcon &, QIcon &, &swap>("swap");
  // QDataStream & operator<<(QDataStream &, const QIcon &);
  binder.operators().put_to<QDataStream &, const QIcon &>();
  // QDataStream & operator>>(QDataStream &, QIcon &);
  binder.operators().read_from<QDataStream &, QIcon &>();
  // QDebug operator<<(QDebug, const QIcon &);
  binder.operators().left_shift<QDebug, QDebug, const QIcon &>();
}

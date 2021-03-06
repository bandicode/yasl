// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/vector3d.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/genericvarianthandler.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/point.h"
#include "yasl/gui/vector2d.h"
#include "yasl/gui/vector3d.h"
#include "yasl/gui/vector4d.h"

#include <script/classbuilder.h>

static void register_vector3_d_class(script::Namespace ns)
{
  using namespace script;

  Class vector3_d = ns.newClass("Vector3D").setId(script::Type::QVector3D).get();


  // QVector3D();
  bind::default_constructor<QVector3D>(vector3_d).create();
  // QVector3D(const QVector3D &);
  bind::constructor<QVector3D, const QVector3D &>(vector3_d).create();
  // ~QVector3D();
  bind::destructor<QVector3D>(vector3_d).create();
  // QVector3D & operator=(const QVector3D &);
  bind::memop_assign<QVector3D, const QVector3D &>(vector3_d);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  // QVector3D(Qt::Initialization);
  bind::constructor<QVector3D, Qt::Initialization>(vector3_d).create();
#endif
  // QVector3D(float, float, float);
  bind::constructor<QVector3D, float, float, float>(vector3_d).create();
  // QVector3D(const QPoint &);
  bind::constructor<QVector3D, const QPoint &>(vector3_d).create();
  // QVector3D(const QPointF &);
  bind::constructor<QVector3D, const QPointF &>(vector3_d).create();
  // QVector3D(const QVector2D &);
  bind::constructor<QVector3D, const QVector2D &>(vector3_d).create();
  // QVector3D(const QVector2D &, float);
  bind::constructor<QVector3D, const QVector2D &, float>(vector3_d).create();
  // QVector3D(const QVector4D &);
  bind::constructor<QVector3D, const QVector4D &>(vector3_d).create();
  // bool isNull() const;
  bind::member_function<QVector3D, bool, &QVector3D::isNull>(vector3_d, "isNull").create();
  // float x() const;
  bind::member_function<QVector3D, float, &QVector3D::x>(vector3_d, "x").create();
  // float y() const;
  bind::member_function<QVector3D, float, &QVector3D::y>(vector3_d, "y").create();
  // float z() const;
  bind::member_function<QVector3D, float, &QVector3D::z>(vector3_d, "z").create();
  // void setX(float);
  bind::void_member_function<QVector3D, float, &QVector3D::setX>(vector3_d, "setX").create();
  // void setY(float);
  bind::void_member_function<QVector3D, float, &QVector3D::setY>(vector3_d, "setY").create();
  // void setZ(float);
  bind::void_member_function<QVector3D, float, &QVector3D::setZ>(vector3_d, "setZ").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // float operator[](int) const;
  bind::memop_const_subscript<QVector3D, float, int>(vector3_d);
#endif
  // float length() const;
  bind::member_function<QVector3D, float, &QVector3D::length>(vector3_d, "length").create();
  // float lengthSquared() const;
  bind::member_function<QVector3D, float, &QVector3D::lengthSquared>(vector3_d, "lengthSquared").create();
  // QVector3D normalized() const;
  bind::member_function<QVector3D, QVector3D, &QVector3D::normalized>(vector3_d, "normalized").create();
  // void normalize();
  bind::void_member_function<QVector3D, &QVector3D::normalize>(vector3_d, "normalize").create();
  // QVector3D & operator+=(const QVector3D &);
  bind::memop_add_assign<QVector3D, const QVector3D &>(vector3_d);
  // QVector3D & operator-=(const QVector3D &);
  bind::memop_sub_assign<QVector3D, const QVector3D &>(vector3_d);
  // QVector3D & operator*=(float);
  bind::memop_mul_assign<QVector3D, float>(vector3_d);
  // QVector3D & operator*=(const QVector3D &);
  bind::memop_mul_assign<QVector3D, const QVector3D &>(vector3_d);
  // QVector3D & operator/=(float);
  bind::memop_div_assign<QVector3D, float>(vector3_d);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  // QVector3D & operator/=(const QVector3D &);
  bind::memop_div_assign<QVector3D, const QVector3D &>(vector3_d);
#endif
  // static float dotProduct(const QVector3D &, const QVector3D &);
  bind::static_member_function<QVector3D, float, const QVector3D &, const QVector3D &, &QVector3D::dotProduct>(vector3_d, "dotProduct").create();
  // static QVector3D crossProduct(const QVector3D &, const QVector3D &);
  bind::static_member_function<QVector3D, QVector3D, const QVector3D &, const QVector3D &, &QVector3D::crossProduct>(vector3_d, "crossProduct").create();
  // static QVector3D normal(const QVector3D &, const QVector3D &);
  bind::static_member_function<QVector3D, QVector3D, const QVector3D &, const QVector3D &, &QVector3D::normal>(vector3_d, "normal").create();
  // static QVector3D normal(const QVector3D &, const QVector3D &, const QVector3D &);
  bind::static_member_function<QVector3D, QVector3D, const QVector3D &, const QVector3D &, const QVector3D &, &QVector3D::normal>(vector3_d, "normal").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  // QVector3D project(const QMatrix4x4 &, const QMatrix4x4 &, const QRect &) const;
  /// TODO: QVector3D project(const QMatrix4x4 &, const QMatrix4x4 &, const QRect &) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  // QVector3D unproject(const QMatrix4x4 &, const QMatrix4x4 &, const QRect &) const;
  /// TODO: QVector3D unproject(const QMatrix4x4 &, const QMatrix4x4 &, const QRect &) const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  // float distanceToPoint(const QVector3D &) const;
  bind::member_function<QVector3D, float, const QVector3D &, &QVector3D::distanceToPoint>(vector3_d, "distanceToPoint").create();
#endif
  // float distanceToPlane(const QVector3D &, const QVector3D &) const;
  bind::member_function<QVector3D, float, const QVector3D &, const QVector3D &, &QVector3D::distanceToPlane>(vector3_d, "distanceToPlane").create();
  // float distanceToPlane(const QVector3D &, const QVector3D &, const QVector3D &) const;
  bind::member_function<QVector3D, float, const QVector3D &, const QVector3D &, const QVector3D &, &QVector3D::distanceToPlane>(vector3_d, "distanceToPlane").create();
  // float distanceToLine(const QVector3D &, const QVector3D &) const;
  bind::member_function<QVector3D, float, const QVector3D &, const QVector3D &, &QVector3D::distanceToLine>(vector3_d, "distanceToLine").create();
  // QVector2D toVector2D() const;
  bind::member_function<QVector3D, QVector2D, &QVector3D::toVector2D>(vector3_d, "toVector2D").create();
  // QVector4D toVector4D() const;
  bind::member_function<QVector3D, QVector4D, &QVector3D::toVector4D>(vector3_d, "toVector4D").create();
  // QPoint toPoint() const;
  bind::member_function<QVector3D, QPoint, &QVector3D::toPoint>(vector3_d, "toPoint").create();
  // QPointF toPointF() const;
  bind::member_function<QVector3D, QPointF, &QVector3D::toPointF>(vector3_d, "toPointF").create();

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QVector3D, QMetaType::QVector3D>>();
}


void register_vector3d_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_vector3_d_class(ns);

  // bool operator==(const QVector3D &, const QVector3D &);
  bind::op_eq<const QVector3D &, const QVector3D &>(ns);
  // bool operator!=(const QVector3D &, const QVector3D &);
  bind::op_neq<const QVector3D &, const QVector3D &>(ns);
  // const QVector3D operator+(const QVector3D &, const QVector3D &);
  bind::op_add<const QVector3D, const QVector3D &, const QVector3D &>(ns);
  // const QVector3D operator-(const QVector3D &, const QVector3D &);
  bind::op_sub<const QVector3D, const QVector3D &, const QVector3D &>(ns);
  // const QVector3D operator*(float, const QVector3D &);
  bind::op_mul<const QVector3D, float, const QVector3D &>(ns);
  // const QVector3D operator*(const QVector3D &, float);
  bind::op_mul<const QVector3D, const QVector3D &, float>(ns);
  // const QVector3D operator*(const QVector3D &, const QVector3D &);
  bind::op_mul<const QVector3D, const QVector3D &, const QVector3D &>(ns);
  // const QVector3D operator-(const QVector3D &);
  bind::op_unary_minus<const QVector3D, const QVector3D &>(ns);
  // const QVector3D operator/(const QVector3D &, float);
  bind::op_div<const QVector3D, const QVector3D &, float>(ns);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  // const QVector3D operator/(const QVector3D &, const QVector3D &);
  bind::op_div<const QVector3D, const QVector3D &, const QVector3D &>(ns);
#endif
  // bool qFuzzyCompare(const QVector3D &, const QVector3D &);
  bind::function<bool, const QVector3D &, const QVector3D &, &qFuzzyCompare>(ns, "qFuzzyCompare").create();
  // QDebug operator<<(QDebug, const QVector3D &);
  /// TODO: QDebug operator<<(QDebug, const QVector3D &);
  // QDataStream & operator<<(QDataStream &, const QVector3D &);
  bind::op_put_to<QDataStream &, const QVector3D &>(ns);
  // QDataStream & operator>>(QDataStream &, QVector3D &);
  bind::op_read_from<QDataStream &, QVector3D &>(ns);
}

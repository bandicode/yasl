// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_RESIZE_EVENT_H
#define YASL_GUI_RESIZE_EVENT_H

#include "yasl/core/event.h"

#include <QResizeEvent>

namespace binding
{

template<> struct make_type_t<QResizeEvent> { inline static script::Type get() { return script::Type::QResizeEvent; } };
template<> struct tag_resolver<QResizeEvent> { typedef qevent_tag tag_type; };

} // namespace binding

#endif // YASL_GUI_RESIZE_EVENT_H

// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/radiobutton.h"

#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_radio_button_class(script::Namespace ns)
{
  using namespace script;

  Class radio_button = ns.Class("RadioButton").setId(script::Type::QRadioButton)
    .setBase(script::Type::QAbstractButton).get();

  binding::QClass<QRadioButton> binder{ radio_button, &QRadioButton::staticMetaObject };

  // QRadioButton(QWidget *);
  binder.ctors().add<QWidget *>();
  // QRadioButton(const QString &, QWidget *);
  binder.ctors().add<const QString &, QWidget *>();
  // ~QRadioButton();
  binder.add_dtor();

  radio_button.engine()->registerQtType(&QRadioButton::staticMetaObject, radio_button.id());
}


void register_radiobutton_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_radio_button_class(ns);
  binding::Namespace binder{ ns };

}

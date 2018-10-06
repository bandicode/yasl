// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/messagebox.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"
#include "yasl/core/flags.h"

#include "yasl/core/enums.h"
#include "yasl/core/object.h"
#include "yasl/gui/pixmap.h"
#include "yasl/widgets/messagebox.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_message_box_icon_enum(script::Class message_box)
{
  using namespace script;

  Enum icon = message_box.Enum("Icon").setId(script::Type::QMessageBoxIcon).get();

  icon.addValue("NoIcon", QMessageBox::NoIcon);
  icon.addValue("Information", QMessageBox::Information);
  icon.addValue("Warning", QMessageBox::Warning);
  icon.addValue("Critical", QMessageBox::Critical);
  icon.addValue("Question", QMessageBox::Question);
}


static void register_message_box_button_role_enum(script::Class message_box)
{
  using namespace script;

  Enum button_role = message_box.Enum("ButtonRole").setId(script::Type::QMessageBoxButtonRole).get();

  button_role.addValue("InvalidRole", QMessageBox::InvalidRole);
  button_role.addValue("AcceptRole", QMessageBox::AcceptRole);
  button_role.addValue("RejectRole", QMessageBox::RejectRole);
  button_role.addValue("DestructiveRole", QMessageBox::DestructiveRole);
  button_role.addValue("ActionRole", QMessageBox::ActionRole);
  button_role.addValue("HelpRole", QMessageBox::HelpRole);
  button_role.addValue("YesRole", QMessageBox::YesRole);
  button_role.addValue("NoRole", QMessageBox::NoRole);
  button_role.addValue("ResetRole", QMessageBox::ResetRole);
  button_role.addValue("ApplyRole", QMessageBox::ApplyRole);
  button_role.addValue("NRoles", QMessageBox::NRoles);
}


static void register_message_box_standard_button_enum(script::Class message_box)
{
  using namespace script;

  Enum standard_button = message_box.Enum("StandardButton").setId(script::Type::QMessageBoxStandardButton).get();

  register_qflags_type<QMessageBox::StandardButton>(message_box, "StandardButtons", script::Type::QMessageBoxStandardButtons);
  standard_button.addValue("NoButton", QMessageBox::NoButton);
  standard_button.addValue("Ok", QMessageBox::Ok);
  standard_button.addValue("Save", QMessageBox::Save);
  standard_button.addValue("SaveAll", QMessageBox::SaveAll);
  standard_button.addValue("Open", QMessageBox::Open);
  standard_button.addValue("Yes", QMessageBox::Yes);
  standard_button.addValue("YesToAll", QMessageBox::YesToAll);
  standard_button.addValue("No", QMessageBox::No);
  standard_button.addValue("NoToAll", QMessageBox::NoToAll);
  standard_button.addValue("Abort", QMessageBox::Abort);
  standard_button.addValue("Retry", QMessageBox::Retry);
  standard_button.addValue("Ignore", QMessageBox::Ignore);
  standard_button.addValue("Close", QMessageBox::Close);
  standard_button.addValue("Cancel", QMessageBox::Cancel);
  standard_button.addValue("Discard", QMessageBox::Discard);
  standard_button.addValue("Help", QMessageBox::Help);
  standard_button.addValue("Apply", QMessageBox::Apply);
  standard_button.addValue("Reset", QMessageBox::Reset);
  standard_button.addValue("RestoreDefaults", QMessageBox::RestoreDefaults);
  standard_button.addValue("FirstButton", QMessageBox::FirstButton);
  standard_button.addValue("LastButton", QMessageBox::LastButton);
  standard_button.addValue("YesAll", QMessageBox::YesAll);
  standard_button.addValue("NoAll", QMessageBox::NoAll);
  standard_button.addValue("Default", QMessageBox::Default);
  standard_button.addValue("Escape", QMessageBox::Escape);
  standard_button.addValue("FlagMask", QMessageBox::FlagMask);
  standard_button.addValue("ButtonMask", QMessageBox::ButtonMask);
}


static void register_message_box_class(script::Namespace ns)
{
  using namespace script;

  Class message_box = ns.Class("MessageBox").setId(script::Type::QMessageBox)
    .setBase(script::Type::QDialog).get();

  register_message_box_icon_enum(message_box);
  register_message_box_button_role_enum(message_box);
  register_message_box_standard_button_enum(message_box);
  binding::QClass<QMessageBox> binder{ message_box, &QMessageBox::staticMetaObject };

  // QMessageBox(QWidget *);
  binder.ctors().add<QWidget *>();
  // QMessageBox(QMessageBox::Icon, const QString &, const QString &, QMessageBox::StandardButtons, QWidget *, Qt::WindowFlags);
  /// TODO: QMessageBox(QMessageBox::Icon, const QString &, const QString &, QMessageBox::StandardButtons, QWidget *, Qt::WindowFlags);
  // ~QMessageBox();
  binder.add_dtor();
  // void addButton(QAbstractButton *, QMessageBox::ButtonRole);
  /// TODO: void addButton(QAbstractButton *, QMessageBox::ButtonRole);
  // QPushButton * addButton(const QString &, QMessageBox::ButtonRole);
  /// TODO: QPushButton * addButton(const QString &, QMessageBox::ButtonRole);
  // QPushButton * addButton(QMessageBox::StandardButton);
  /// TODO: QPushButton * addButton(QMessageBox::StandardButton);
  // void removeButton(QAbstractButton *);
  /// TODO: void removeButton(QAbstractButton *);
  // void open(QObject *, const char *);
  /// TODO: void open(QObject *, const char *);
  // QList<QAbstractButton *> buttons() const;
  /// TODO: QList<QAbstractButton *> buttons() const;
  // QMessageBox::ButtonRole buttonRole(QAbstractButton *) const;
  /// TODO: QMessageBox::ButtonRole buttonRole(QAbstractButton *) const;
  // void setStandardButtons(QMessageBox::StandardButtons);
  binder.add_void_fun<QMessageBox::StandardButtons, &QMessageBox::setStandardButtons>("setStandardButtons");
  // QMessageBox::StandardButtons standardButtons() const;
  binder.add_fun<QMessageBox::StandardButtons, &QMessageBox::standardButtons>("standardButtons");
  // QMessageBox::StandardButton standardButton(QAbstractButton *) const;
  /// TODO: QMessageBox::StandardButton standardButton(QAbstractButton *) const;
  // QAbstractButton * button(QMessageBox::StandardButton) const;
  /// TODO: QAbstractButton * button(QMessageBox::StandardButton) const;
  // QPushButton * defaultButton() const;
  /// TODO: QPushButton * defaultButton() const;
  // void setDefaultButton(QPushButton *);
  /// TODO: void setDefaultButton(QPushButton *);
  // void setDefaultButton(QMessageBox::StandardButton);
  binder.add_void_fun<QMessageBox::StandardButton, &QMessageBox::setDefaultButton>("setDefaultButton");
  // QAbstractButton * escapeButton() const;
  /// TODO: QAbstractButton * escapeButton() const;
  // void setEscapeButton(QAbstractButton *);
  /// TODO: void setEscapeButton(QAbstractButton *);
  // void setEscapeButton(QMessageBox::StandardButton);
  binder.add_void_fun<QMessageBox::StandardButton, &QMessageBox::setEscapeButton>("setEscapeButton");
  // QAbstractButton * clickedButton() const;
  /// TODO: QAbstractButton * clickedButton() const;
  // QString text() const;
  binder.add_fun<QString, &QMessageBox::text>("text");
  // void setText(const QString &);
  binder.add_void_fun<const QString &, &QMessageBox::setText>("setText");
  // QMessageBox::Icon icon() const;
  binder.add_fun<QMessageBox::Icon, &QMessageBox::icon>("icon");
  // void setIcon(QMessageBox::Icon);
  binder.add_void_fun<QMessageBox::Icon, &QMessageBox::setIcon>("setIcon");
  // QPixmap iconPixmap() const;
  binder.add_fun<QPixmap, &QMessageBox::iconPixmap>("iconPixmap");
  // void setIconPixmap(const QPixmap &);
  binder.add_void_fun<const QPixmap &, &QMessageBox::setIconPixmap>("setIconPixmap");
  // Qt::TextFormat textFormat() const;
  binder.add_fun<Qt::TextFormat, &QMessageBox::textFormat>("textFormat");
  // void setTextFormat(Qt::TextFormat);
  binder.add_void_fun<Qt::TextFormat, &QMessageBox::setTextFormat>("setTextFormat");
  // void setTextInteractionFlags(Qt::TextInteractionFlags);
  /// TODO: void setTextInteractionFlags(Qt::TextInteractionFlags);
  // Qt::TextInteractionFlags textInteractionFlags() const;
  /// TODO: Qt::TextInteractionFlags textInteractionFlags() const;
  // void setCheckBox(QCheckBox *);
  /// TODO: void setCheckBox(QCheckBox *);
  // QCheckBox * checkBox() const;
  /// TODO: QCheckBox * checkBox() const;
  // static QMessageBox::StandardButton information(QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton);
  binder.add_static<QMessageBox::StandardButton, QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton, &QMessageBox::information>("information");
  // static QMessageBox::StandardButton question(QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton);
  binder.add_static<QMessageBox::StandardButton, QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton, &QMessageBox::question>("question");
  // static QMessageBox::StandardButton warning(QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton);
  binder.add_static<QMessageBox::StandardButton, QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton, &QMessageBox::warning>("warning");
  // static QMessageBox::StandardButton critical(QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton);
  binder.add_static<QMessageBox::StandardButton, QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton, &QMessageBox::critical>("critical");
  // static void about(QWidget *, const QString &, const QString &);
  binder.add_static_void_fun<QWidget *, const QString &, const QString &, &QMessageBox::about>("about");
  // static void aboutQt(QWidget *, const QString &);
  binder.add_static_void_fun<QWidget *, const QString &, &QMessageBox::aboutQt>("aboutQt");
  // QMessageBox(const QString &, const QString &, QMessageBox::Icon, int, int, int, QWidget *, Qt::WindowFlags);
  /// TODO: QMessageBox(const QString &, const QString &, QMessageBox::Icon, int, int, int, QWidget *, Qt::WindowFlags);
  // static QMessageBox::StandardButton information(QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton);
  binder.add_static<QMessageBox::StandardButton, QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton, &QMessageBox::information>("information");
  // static int question(QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton);
  binder.add_static<int, QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton, &QMessageBox::question>("question");
  // static int warning(QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton);
  binder.add_static<int, QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton, &QMessageBox::warning>("warning");
  // static int critical(QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton);
  binder.add_static<int, QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton, &QMessageBox::critical>("critical");
  // QString buttonText(int) const;
  binder.add_fun<QString, int, &QMessageBox::buttonText>("buttonText");
  // void setButtonText(int, const QString &);
  binder.add_void_fun<int, const QString &, &QMessageBox::setButtonText>("setButtonText");
  // QString informativeText() const;
  binder.add_fun<QString, &QMessageBox::informativeText>("informativeText");
  // void setInformativeText(const QString &);
  binder.add_void_fun<const QString &, &QMessageBox::setInformativeText>("setInformativeText");
  // QString detailedText() const;
  binder.add_fun<QString, &QMessageBox::detailedText>("detailedText");
  // void setDetailedText(const QString &);
  binder.add_void_fun<const QString &, &QMessageBox::setDetailedText>("setDetailedText");
  // void setWindowTitle(const QString &);
  binder.add_void_fun<const QString &, &QMessageBox::setWindowTitle>("setWindowTitle");
  // void setWindowModality(Qt::WindowModality);
  binder.add_void_fun<Qt::WindowModality, &QMessageBox::setWindowModality>("setWindowModality");
  // static QPixmap standardIcon(QMessageBox::Icon);
  binder.add_static<QPixmap, QMessageBox::Icon, &QMessageBox::standardIcon>("standardIcon");
  // void buttonClicked(QAbstractButton *);
  /// TODO: void buttonClicked(QAbstractButton *);

  message_box.engine()->registerQtType(&QMessageBox::staticMetaObject, message_box.id());
}


void register_messagebox_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_message_box_class(ns);
  binding::Namespace binder{ ns };

  // QFlags<QMessageBox::StandardButtons::enum_type> operator|(QMessageBox::StandardButtons::enum_type, QMessageBox::StandardButtons::enum_type);
  /// TODO: QFlags<QMessageBox::StandardButtons::enum_type> operator|(QMessageBox::StandardButtons::enum_type, QMessageBox::StandardButtons::enum_type);
  // QFlags<QMessageBox::StandardButtons::enum_type> operator|(QMessageBox::StandardButtons::enum_type, QFlags<QMessageBox::StandardButtons::enum_type>);
  /// TODO: QFlags<QMessageBox::StandardButtons::enum_type> operator|(QMessageBox::StandardButtons::enum_type, QFlags<QMessageBox::StandardButtons::enum_type>);
  // QIncompatibleFlag operator|(QMessageBox::StandardButtons::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QMessageBox::StandardButtons::enum_type, int);
}

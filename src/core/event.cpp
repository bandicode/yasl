// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/event.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/qevent-binder.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/event.h"
#include "yasl/core/object.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_event_type_enum(script::Class event)
{
  using namespace script;

  Enum type = event.Enum("Type").setId(script::Type::QEventType).get();

  type.addValue("None", QEvent::None);
  type.addValue("Timer", QEvent::Timer);
  type.addValue("MouseButtonPress", QEvent::MouseButtonPress);
  type.addValue("MouseButtonRelease", QEvent::MouseButtonRelease);
  type.addValue("MouseButtonDblClick", QEvent::MouseButtonDblClick);
  type.addValue("MouseMove", QEvent::MouseMove);
  type.addValue("KeyPress", QEvent::KeyPress);
  type.addValue("KeyRelease", QEvent::KeyRelease);
  type.addValue("FocusIn", QEvent::FocusIn);
  type.addValue("FocusOut", QEvent::FocusOut);
  type.addValue("FocusAboutToChange", QEvent::FocusAboutToChange);
  type.addValue("Enter", QEvent::Enter);
  type.addValue("Leave", QEvent::Leave);
  type.addValue("Paint", QEvent::Paint);
  type.addValue("Move", QEvent::Move);
  type.addValue("Resize", QEvent::Resize);
  type.addValue("Create", QEvent::Create);
  type.addValue("Destroy", QEvent::Destroy);
  type.addValue("Show", QEvent::Show);
  type.addValue("Hide", QEvent::Hide);
  type.addValue("Close", QEvent::Close);
  type.addValue("Quit", QEvent::Quit);
  type.addValue("ParentChange", QEvent::ParentChange);
  type.addValue("ParentAboutToChange", QEvent::ParentAboutToChange);
  type.addValue("ThreadChange", QEvent::ThreadChange);
  type.addValue("WindowActivate", QEvent::WindowActivate);
  type.addValue("WindowDeactivate", QEvent::WindowDeactivate);
  type.addValue("ShowToParent", QEvent::ShowToParent);
  type.addValue("HideToParent", QEvent::HideToParent);
  type.addValue("Wheel", QEvent::Wheel);
  type.addValue("WindowTitleChange", QEvent::WindowTitleChange);
  type.addValue("WindowIconChange", QEvent::WindowIconChange);
  type.addValue("ApplicationWindowIconChange", QEvent::ApplicationWindowIconChange);
  type.addValue("ApplicationFontChange", QEvent::ApplicationFontChange);
  type.addValue("ApplicationLayoutDirectionChange", QEvent::ApplicationLayoutDirectionChange);
  type.addValue("ApplicationPaletteChange", QEvent::ApplicationPaletteChange);
  type.addValue("PaletteChange", QEvent::PaletteChange);
  type.addValue("Clipboard", QEvent::Clipboard);
  type.addValue("Speech", QEvent::Speech);
  type.addValue("MetaCall", QEvent::MetaCall);
  type.addValue("SockAct", QEvent::SockAct);
  type.addValue("WinEventAct", QEvent::WinEventAct);
  type.addValue("DeferredDelete", QEvent::DeferredDelete);
  type.addValue("DragEnter", QEvent::DragEnter);
  type.addValue("DragMove", QEvent::DragMove);
  type.addValue("DragLeave", QEvent::DragLeave);
  type.addValue("Drop", QEvent::Drop);
  type.addValue("DragResponse", QEvent::DragResponse);
  type.addValue("ChildAdded", QEvent::ChildAdded);
  type.addValue("ChildPolished", QEvent::ChildPolished);
  type.addValue("ChildRemoved", QEvent::ChildRemoved);
  type.addValue("ShowWindowRequest", QEvent::ShowWindowRequest);
  type.addValue("PolishRequest", QEvent::PolishRequest);
  type.addValue("Polish", QEvent::Polish);
  type.addValue("LayoutRequest", QEvent::LayoutRequest);
  type.addValue("UpdateRequest", QEvent::UpdateRequest);
  type.addValue("UpdateLater", QEvent::UpdateLater);
  type.addValue("EmbeddingControl", QEvent::EmbeddingControl);
  type.addValue("ActivateControl", QEvent::ActivateControl);
  type.addValue("DeactivateControl", QEvent::DeactivateControl);
  type.addValue("ContextMenu", QEvent::ContextMenu);
  type.addValue("InputMethod", QEvent::InputMethod);
  type.addValue("TabletMove", QEvent::TabletMove);
  type.addValue("LocaleChange", QEvent::LocaleChange);
  type.addValue("LanguageChange", QEvent::LanguageChange);
  type.addValue("LayoutDirectionChange", QEvent::LayoutDirectionChange);
  type.addValue("Style", QEvent::Style);
  type.addValue("TabletPress", QEvent::TabletPress);
  type.addValue("TabletRelease", QEvent::TabletRelease);
  type.addValue("OkRequest", QEvent::OkRequest);
  type.addValue("HelpRequest", QEvent::HelpRequest);
  type.addValue("IconDrag", QEvent::IconDrag);
  type.addValue("FontChange", QEvent::FontChange);
  type.addValue("EnabledChange", QEvent::EnabledChange);
  type.addValue("ActivationChange", QEvent::ActivationChange);
  type.addValue("StyleChange", QEvent::StyleChange);
  type.addValue("IconTextChange", QEvent::IconTextChange);
  type.addValue("ModifiedChange", QEvent::ModifiedChange);
  type.addValue("MouseTrackingChange", QEvent::MouseTrackingChange);
  type.addValue("WindowBlocked", QEvent::WindowBlocked);
  type.addValue("WindowUnblocked", QEvent::WindowUnblocked);
  type.addValue("WindowStateChange", QEvent::WindowStateChange);
  type.addValue("ReadOnlyChange", QEvent::ReadOnlyChange);
  type.addValue("ToolTip", QEvent::ToolTip);
  type.addValue("WhatsThis", QEvent::WhatsThis);
  type.addValue("StatusTip", QEvent::StatusTip);
  type.addValue("ActionChanged", QEvent::ActionChanged);
  type.addValue("ActionAdded", QEvent::ActionAdded);
  type.addValue("ActionRemoved", QEvent::ActionRemoved);
  type.addValue("FileOpen", QEvent::FileOpen);
  type.addValue("Shortcut", QEvent::Shortcut);
  type.addValue("ShortcutOverride", QEvent::ShortcutOverride);
  type.addValue("WhatsThisClicked", QEvent::WhatsThisClicked);
  type.addValue("ToolBarChange", QEvent::ToolBarChange);
  type.addValue("ApplicationActivate", QEvent::ApplicationActivate);
  type.addValue("ApplicationActivated", QEvent::ApplicationActivated);
  type.addValue("ApplicationDeactivate", QEvent::ApplicationDeactivate);
  type.addValue("ApplicationDeactivated", QEvent::ApplicationDeactivated);
  type.addValue("QueryWhatsThis", QEvent::QueryWhatsThis);
  type.addValue("EnterWhatsThisMode", QEvent::EnterWhatsThisMode);
  type.addValue("LeaveWhatsThisMode", QEvent::LeaveWhatsThisMode);
  type.addValue("ZOrderChange", QEvent::ZOrderChange);
  type.addValue("HoverEnter", QEvent::HoverEnter);
  type.addValue("HoverLeave", QEvent::HoverLeave);
  type.addValue("HoverMove", QEvent::HoverMove);
  type.addValue("AcceptDropsChange", QEvent::AcceptDropsChange);
  type.addValue("ZeroTimerEvent", QEvent::ZeroTimerEvent);
  type.addValue("GraphicsSceneMouseMove", QEvent::GraphicsSceneMouseMove);
  type.addValue("GraphicsSceneMousePress", QEvent::GraphicsSceneMousePress);
  type.addValue("GraphicsSceneMouseRelease", QEvent::GraphicsSceneMouseRelease);
  type.addValue("GraphicsSceneMouseDoubleClick", QEvent::GraphicsSceneMouseDoubleClick);
  type.addValue("GraphicsSceneContextMenu", QEvent::GraphicsSceneContextMenu);
  type.addValue("GraphicsSceneHoverEnter", QEvent::GraphicsSceneHoverEnter);
  type.addValue("GraphicsSceneHoverMove", QEvent::GraphicsSceneHoverMove);
  type.addValue("GraphicsSceneHoverLeave", QEvent::GraphicsSceneHoverLeave);
  type.addValue("GraphicsSceneHelp", QEvent::GraphicsSceneHelp);
  type.addValue("GraphicsSceneDragEnter", QEvent::GraphicsSceneDragEnter);
  type.addValue("GraphicsSceneDragMove", QEvent::GraphicsSceneDragMove);
  type.addValue("GraphicsSceneDragLeave", QEvent::GraphicsSceneDragLeave);
  type.addValue("GraphicsSceneDrop", QEvent::GraphicsSceneDrop);
  type.addValue("GraphicsSceneWheel", QEvent::GraphicsSceneWheel);
  type.addValue("KeyboardLayoutChange", QEvent::KeyboardLayoutChange);
  type.addValue("DynamicPropertyChange", QEvent::DynamicPropertyChange);
  type.addValue("TabletEnterProximity", QEvent::TabletEnterProximity);
  type.addValue("TabletLeaveProximity", QEvent::TabletLeaveProximity);
  type.addValue("NonClientAreaMouseMove", QEvent::NonClientAreaMouseMove);
  type.addValue("NonClientAreaMouseButtonPress", QEvent::NonClientAreaMouseButtonPress);
  type.addValue("NonClientAreaMouseButtonRelease", QEvent::NonClientAreaMouseButtonRelease);
  type.addValue("NonClientAreaMouseButtonDblClick", QEvent::NonClientAreaMouseButtonDblClick);
  type.addValue("MacSizeChange", QEvent::MacSizeChange);
  type.addValue("ContentsRectChange", QEvent::ContentsRectChange);
  type.addValue("MacGLWindowChange", QEvent::MacGLWindowChange);
  type.addValue("FutureCallOut", QEvent::FutureCallOut);
  type.addValue("GraphicsSceneResize", QEvent::GraphicsSceneResize);
  type.addValue("GraphicsSceneMove", QEvent::GraphicsSceneMove);
  type.addValue("CursorChange", QEvent::CursorChange);
  type.addValue("ToolTipChange", QEvent::ToolTipChange);
  type.addValue("NetworkReplyUpdated", QEvent::NetworkReplyUpdated);
  type.addValue("GrabMouse", QEvent::GrabMouse);
  type.addValue("UngrabMouse", QEvent::UngrabMouse);
  type.addValue("GrabKeyboard", QEvent::GrabKeyboard);
  type.addValue("UngrabKeyboard", QEvent::UngrabKeyboard);
  type.addValue("MacGLClearDrawable", QEvent::MacGLClearDrawable);
  type.addValue("StateMachineSignal", QEvent::StateMachineSignal);
  type.addValue("StateMachineWrapped", QEvent::StateMachineWrapped);
  type.addValue("TouchBegin", QEvent::TouchBegin);
  type.addValue("TouchUpdate", QEvent::TouchUpdate);
  type.addValue("TouchEnd", QEvent::TouchEnd);
  type.addValue("NativeGesture", QEvent::NativeGesture);
  type.addValue("RequestSoftwareInputPanel", QEvent::RequestSoftwareInputPanel);
  type.addValue("CloseSoftwareInputPanel", QEvent::CloseSoftwareInputPanel);
  type.addValue("WinIdChange", QEvent::WinIdChange);
  type.addValue("Gesture", QEvent::Gesture);
  type.addValue("GestureOverride", QEvent::GestureOverride);
  type.addValue("ScrollPrepare", QEvent::ScrollPrepare);
  type.addValue("Scroll", QEvent::Scroll);
  type.addValue("Expose", QEvent::Expose);
  type.addValue("InputMethodQuery", QEvent::InputMethodQuery);
  type.addValue("OrientationChange", QEvent::OrientationChange);
  type.addValue("TouchCancel", QEvent::TouchCancel);
  type.addValue("ThemeChange", QEvent::ThemeChange);
  type.addValue("SockClose", QEvent::SockClose);
  type.addValue("PlatformPanel", QEvent::PlatformPanel);
  type.addValue("StyleAnimationUpdate", QEvent::StyleAnimationUpdate);
  type.addValue("ApplicationStateChange", QEvent::ApplicationStateChange);
  type.addValue("WindowChangeInternal", QEvent::WindowChangeInternal);
  type.addValue("ScreenChangeInternal", QEvent::ScreenChangeInternal);
  type.addValue("PlatformSurface", QEvent::PlatformSurface);
  type.addValue("Pointer", QEvent::Pointer);
  type.addValue("TabletTrackingChange", QEvent::TabletTrackingChange);
  type.addValue("User", QEvent::User);
  type.addValue("MaxUser", QEvent::MaxUser);
}


static void register_event_class(script::Namespace ns)
{
  using namespace script;

  Class event = ns.Class("Event").setId(script::Type::QEvent).get();

  register_event_type_enum(event);
  binding::ClassBinder<QEvent> binder{ event };

  // QEvent(QEvent::Type);
  binder.ctor<QEvent::Type>().create();
  // QEvent(const QEvent &);
  binder.ctor<const QEvent &>().create();
  // ~QEvent();
  binder.dtor().create();
  // QEvent & operator=(const QEvent &);
  binder.operators().assign<const QEvent &>();
  // QEvent::Type type() const;
  binder.fun<QEvent::Type, &QEvent::type>("type").create();
  // bool spontaneous() const;
  binder.fun<bool, &QEvent::spontaneous>("spontaneous").create();
  // void setAccepted(bool);
  binder.void_fun<bool, &QEvent::setAccepted>("setAccepted").create();
  // bool isAccepted() const;
  binder.fun<bool, &QEvent::isAccepted>("isAccepted").create();
  // void accept();
  binder.void_fun<&QEvent::accept>("accept").create();
  // void ignore();
  binder.void_fun<&QEvent::ignore>("ignore").create();
  // static int registerEventType(int);
  binder.static_fun<int, int, &QEvent::registerEventType>("registerEventType").create();
}


static void register_timer_event_class(script::Namespace ns)
{
  using namespace script;

  Class timer_event = ns.Class("TimerEvent").setId(script::Type::QTimerEvent).get();

  binding::ClassBinder<QTimerEvent> binder{ timer_event };

  // QTimerEvent(int);
  binder.ctor<int>().create();
  // ~QTimerEvent();
  binder.dtor().create();
  // int timerId() const;
  binder.fun<int, &QTimerEvent::timerId>("timerId").create();
}


static void register_child_event_class(script::Namespace ns)
{
  using namespace script;

  Class child_event = ns.Class("ChildEvent").setId(script::Type::QChildEvent).get();

  binding::ClassBinder<QChildEvent> binder{ child_event };

  // QChildEvent(QEvent::Type, QObject *);
  binder.ctor<QEvent::Type, QObject *>().create();
  // ~QChildEvent();
  binder.dtor().create();
  // QObject * child() const;
  binder.fun<QObject *, &QChildEvent::child>("child").create();
  // bool added() const;
  binder.fun<bool, &QChildEvent::added>("added").create();
  // bool polished() const;
  binder.fun<bool, &QChildEvent::polished>("polished").create();
  // bool removed() const;
  binder.fun<bool, &QChildEvent::removed>("removed").create();
}


static void register_dynamic_property_change_event_class(script::Namespace ns)
{
  using namespace script;

  Class dynamic_property_change_event = ns.Class("DynamicPropertyChangeEvent").setId(script::Type::QDynamicPropertyChangeEvent).get();

  binding::ClassBinder<QDynamicPropertyChangeEvent> binder{ dynamic_property_change_event };

  // QDynamicPropertyChangeEvent(const QByteArray &);
  binder.ctor<const QByteArray &>().create();
  // ~QDynamicPropertyChangeEvent();
  binder.dtor().create();
  // QByteArray propertyName() const;
  binder.fun<QByteArray, &QDynamicPropertyChangeEvent::propertyName>("propertyName").create();
}


static void register_deferred_delete_event_class(script::Namespace ns)
{
  using namespace script;

  Class deferred_delete_event = ns.Class("DeferredDeleteEvent").setId(script::Type::QDeferredDeleteEvent).get();

  binding::ClassBinder<QDeferredDeleteEvent> binder{ deferred_delete_event };

  // QDeferredDeleteEvent();
  binder.default_ctor().create();
  // ~QDeferredDeleteEvent();
  binder.dtor().create();
  // int loopLevel() const;
  binder.fun<int, &QDeferredDeleteEvent::loopLevel>("loopLevel").create();
}


void register_event_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_event_class(ns);
  register_timer_event_class(ns);
  register_child_event_class(ns);
  register_dynamic_property_change_event_class(ns);
  register_deferred_delete_event_class(ns);
  binding::Namespace binder{ ns };

}


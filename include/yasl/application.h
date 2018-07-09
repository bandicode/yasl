// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_APPLICATION_H
#define YASL_APPLICATION_H

#include <QApplication>

#include <script/classtemplate.h>
#include <script/engine.h>

class Application : public QApplication
{
  Q_OBJECT
public:
  Application(int & argc, char **argv);
  ~Application() = default;

  inline script::Engine * scriptEngine() { return &mEngine; }

  void run(const script::SourceFile & src);
  void interactive();
  
private:
  script::Engine mEngine;
};

#if defined(qApp)
#undef qApp
#endif
#define qApp (static_cast<Application *>(QCoreApplication::instance()))

#endif // YASL_APPLICATION_H

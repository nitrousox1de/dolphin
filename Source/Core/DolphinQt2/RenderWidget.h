// Copyright 2015 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include <QEvent>
#include <QTimer>
#include <QWidget>

class RenderWidget final : public QWidget
{
  Q_OBJECT

public:
  explicit RenderWidget(QWidget* parent = nullptr);

  bool event(QEvent* event);

signals:
  void EscapePressed();
  void Closed();
  void HandleChanged(void* handle);
  void FocusChanged(bool focus);
  void StateChanged(bool fullscreen);

private slots:
  void UpdateCursor();

private:
  static constexpr int MOUSE_HIDE_DELAY = 3000;
  QTimer* m_mouse_timer;
};

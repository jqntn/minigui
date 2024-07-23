#pragma once

#include <memory>
#include <minigui/gui.hpp>

namespace minigui {
struct BackendConfig
{
  int window_width = 1280;
  int window_height = 720;
  const char* window_title = "window_title";
  bool show_gl_version = false;
  std::unique_ptr<GUI>&& p_gui;
};
}
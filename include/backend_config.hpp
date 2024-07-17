#pragma once

namespace minigui {
class Renderer;

struct BackendConfig
{
  int window_width = 1280;
  int window_height = 720;
  const char* window_title = "window_title";
  bool show_gl_version = false;
};
}
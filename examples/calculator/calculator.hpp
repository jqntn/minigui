#pragma once

#include <minigui/gui.hpp>

namespace minigui {
class Backend;

class Calculator : public GUI
{
public:
  Calculator(const Backend& backend);

  void init() override;
  void render() override;
  void shutdown() override;
};
}

namespace minigui {
Calculator::Calculator(const Backend& backend)
  : GUI(backend,
        Config{
          .window_width = 1280,
          .window_height = 720,
          .window_title = "calculator",
          .show_gl_version = true,
        })
{
}

void
Calculator::init()
{
}

void
Calculator::render()
{
}

void
Calculator::shutdown()
{
}
}
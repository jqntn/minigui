#pragma once

#include <deps/nuklear.h>
#include <minigui/backend.hpp>
#include <minigui/gui.hpp>

namespace minigui {
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
  nk_context* p_context = m_backend.get_context();

  if (nk_begin(p_context, "", nk_get_null_rect(), NK_WINDOW_BACKGROUND)) {
    nk_end(p_context);
  }
}

void
Calculator::shutdown()
{
}
}
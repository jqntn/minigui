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
  : GUI(backend)
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
#pragma once

#include <memory>
#include <minigui/gui.hpp>

struct GLFWwindow;

namespace minigui {
class Backend
{
public:
  void run(std::unique_ptr<GUI>&& p_gui);

private:
  GLFWwindow* m_p_window = nullptr;

  std::unique_ptr<GUI> m_p_gui;
};
}
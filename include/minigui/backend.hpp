#pragma once

#include <memory>
#include <minigui/gui.hpp>

struct GLFWwindow;

namespace minigui {
struct BackendConfig;

class Backend
{
public:
  void run(const BackendConfig& config);

private:
  GLFWwindow* m_p_window = nullptr;

  std::unique_ptr<GUI> m_p_gui;
};
}
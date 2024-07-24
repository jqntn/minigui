#pragma once

#include <memory>
#include <minigui/gui.hpp>

struct GLFWwindow;
struct nk_context;

namespace minigui {
class Backend
{
public:
  void run(std::unique_ptr<GUI>&& p_gui = nullptr);

  GLFWwindow* get_window() const { return m_p_window; }
  nk_context* get_context() const { return m_p_context; }

private:
  std::unique_ptr<GUI> m_p_gui;

  GLFWwindow* m_p_window = nullptr;
  nk_context* m_p_context = nullptr;
};
}
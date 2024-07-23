#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_GLFW_GL2_IMPLEMENTATION
#define NK_KEYSTATE_BASED_INPUT

#include <GLFW/glfw3.h>
#include <cstdio>
#include <cstdlib>
#include <deps/nuklear.h>
#include <deps/nuklear_glfw_gl2.h>
#include <format>
#include <gl/GL.h>
#include <minigui/backend.hpp>
#include <minigui/backend_config.hpp>
#include <string>
#include <type_traits>

namespace minigui {
void
Backend::run(const BackendConfig& config)
{
  m_p_gui = std::move(config.p_gui);

  glfwSetErrorCallback([](int error_code, const char* description) {
    std::fprintf(stderr, "GLFW Error %d: %s\n", error_code, description);
  });

  if (GLFW_FALSE == glfwInit()) {
    std::abort();
  }

  m_p_window = glfwCreateWindow(config.window_width,
                                config.window_height,
                                config.window_title,
                                nullptr,
                                nullptr);
  if (nullptr == m_p_window) {
    std::abort();
  }

  int count;
  GLFWmonitor** pp_monitors = glfwGetMonitors(&count);
  if (nullptr == pp_monitors) {
    std::abort();
  }
  const GLFWvidmode* p_video_mode = glfwGetVideoMode(pp_monitors[0]);
  if (nullptr == p_video_mode) {
    std::abort();
  }

  int monitor_x, monitor_y;
  glfwGetMonitorPos(pp_monitors[0], &monitor_x, &monitor_y);
  glfwSetWindowPos(
    m_p_window,
    monitor_x + (p_video_mode->width - config.window_width) * 0.5f,
    monitor_y + (p_video_mode->height - config.window_height) * 0.5f);

  glfwMakeContextCurrent(m_p_window);
  glfwSwapInterval(1);

  if (config.show_gl_version) {
    std::string version =
      reinterpret_cast<const char*>(glGetString(GL_VERSION));
    std::string old_title = glfwGetWindowTitle(m_p_window);
    std::string new_title = std::format("{} (OpenGL {})", old_title, version);
    glfwSetWindowTitle(m_p_window, new_title.c_str());
  }

  nk_context* p_nk_context =
    nk_glfw3_init(m_p_window, NK_GLFW3_INSTALL_CALLBACKS);
  if (nullptr == p_nk_context) {
    std::abort();
  }

  nk_font_atlas* atlas = nullptr;
  nk_glfw3_font_stash_begin(&atlas);
  nk_glfw3_font_stash_end();

  if (nullptr != m_p_gui) {
    m_p_gui->init();
  }

  while (GLFW_NO_ERROR == glfwWindowShouldClose(m_p_window)) {
    glfwPollEvents();

    int display_w, display_h;
    glfwGetFramebufferSize(m_p_window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);

    nk_glfw3_new_frame();

    glClear(GL_COLOR_BUFFER_BIT);

    if (nullptr != m_p_gui) {
      m_p_gui->render();
    }

    nk_glfw3_render(NK_ANTI_ALIASING_ON);

    glfwSwapBuffers(m_p_window);
  }

  if (nullptr != m_p_gui) {
    m_p_gui->shutdown();
  }

  nk_glfw3_shutdown();

  glfwDestroyWindow(m_p_window);
  glfwTerminate();
}
}
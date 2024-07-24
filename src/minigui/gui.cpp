#include <deps/nuklear.h>
#include <minigui/backend.hpp>
#include <minigui/gui.hpp>

namespace minigui {
GUI::GUI(const Backend& backend, const Config& config)
  : m_backend(backend)
  , m_config(config)
{
}

void
GUI::init()
{
}

void
GUI::render()
{
  nk_context* p_context = m_backend.get_context();

  if (nk_begin(p_context, "", nk_get_null_rect(), NK_WINDOW_BACKGROUND)) {
    nk_end(p_context);
  }
}

void
GUI::shutdown()
{
}
}
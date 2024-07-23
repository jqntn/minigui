#include <minigui/gui.hpp>

namespace minigui {
GUI::GUI(const Backend& backend, const Config& config)
  : m_backend(backend)
  , m_config(config)
{
}
}
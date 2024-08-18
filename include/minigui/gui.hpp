#pragma once

namespace minigui {
class Backend;

struct Config
{
  int window_width = 1280;
  int window_height = 720;
  const char* window_title = "minigui";
  bool show_gl_version = false;
};

class GUI
{
public:
  GUI(const Backend& backend, const Config& config)
    : m_backend(backend)
    , m_config(config)
  {
  }

  virtual void init() = 0;
  virtual void render() = 0;
  virtual void shutdown() = 0;

  const Config& get_config() const { return m_config; }

protected:
  const Backend& m_backend;

private:
  Config m_config;
};
}
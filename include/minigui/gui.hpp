#pragma once

namespace minigui {
class Backend;

class GUI
{
public:
  GUI(const Backend& backend);

  virtual void init() = 0;
  virtual void render() = 0;
  virtual void shutdown() = 0;

protected:
  const Backend& backend;
};
}
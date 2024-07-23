#include <cstdlib>
#include <examples/calculator/calculator.hpp>
#include <memory>
#include <minigui/backend.hpp>
#include <minigui/backend_config.hpp>

int
main()
{
  minigui::Backend backend;

  minigui::BackendConfig config{
    .window_width = 1280,
    .window_height = 720,
    .window_title = "calculator",
    .show_gl_version = true,
    .p_gui = std::make_unique<minigui::Calculator>(backend),
  };

  backend.run(config);

  return EXIT_SUCCESS;
}
#include <cstdlib>
#include <examples/calculator/calculator.hpp>
#include <memory>
#include <minigui/backend.hpp>

int
main()
{
  minigui::Backend backend;

  backend.run(std::make_unique<minigui::Calculator>(backend));

  return EXIT_SUCCESS;
}
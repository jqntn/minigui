cmake_minimum_required(VERSION 3.15)

project(minigui LANGUAGES CXX)

set(CMAKE_MSVC_RUNTIME_LIBRARY "$<$<NOT:$<CONFIG:Debug>>:MultiThreaded>")

add_executable(minigui)

set_property(TARGET minigui PROPERTY CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
include(FetchContent)
set(FETCHCONTENT_QUIET OFF)
FetchContent_Declare(glfw URL "https://github.com/glfw/glfw/archive/refs/tags/3.4.tar.gz")
FetchContent_MakeAvailable(glfw)

file(GLOB_RECURSE minigui_src "src/*.cpp")
target_sources(minigui PRIVATE
  "${minigui_src}")

target_include_directories(minigui PRIVATE
  "include"
  "${glfw_SOURCE_DIR}")

target_link_libraries(minigui PRIVATE
  OpenGL::GL
  glfw)

if(MSVC)
  target_link_options(minigui PRIVATE "$<$<NOT:$<CONFIG:Debug>>:LINKER:/SUBSYSTEM:WINDOWS,/ENTRY:mainCRTStartup>")
endif()
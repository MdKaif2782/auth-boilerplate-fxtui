cmake_minimum_required(VERSION 3.29)
project(auth_boilerplate_ftxui)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(external/ftxui)
add_executable(auth_boilerplate_ftxui main.cpp)
target_link_libraries(auth_boilerplate_ftxui
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
)

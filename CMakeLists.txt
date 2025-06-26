cmake_minimum_required(VERSION 3.29)
project(auth_boilerplate_ftxui)

set(CMAKE_CXX_STANDARD 20)


#ftxui install
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
        GIT_TAG v6.1.9  # Replace with a version, tag, or commit hash
)

FetchContent_MakeAvailable(ftxui)


add_executable(auth_boilerplate_ftxui main.cpp)
target_link_libraries(main
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
)

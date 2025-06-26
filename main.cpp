#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <iostream>

using namespace ftxui;

int main() {
    std::string username;
    std::string password;
    bool login_failed = false;

    // Input components
    Component input_username = Input(&username, "username");

    // Password input with masking
    InputOption password_option;
    password_option.password = true;
    Component input_password = Input(&password, "password", password_option);

    // Login button component
    Component login_button = Button(
        "Login",
        [&] {
            if (username == "admin" && password == "password123") {
                std::cout << "Login successful!\n";
                exit(0);
            } else {
                login_failed = true;
            }
        }
    );

    // Quit button component
    Component quit_button = Button(
        "Quit",
        [] { exit(0); }
    );

    // Create the login form
    Component login_form = Container::Vertical({
        input_username,
        input_password,
        Container::Horizontal({
            login_button,
            quit_button,
        }),
    });

    // Render function
    auto renderer = Renderer(login_form, [&] {
        return vbox({
            // Title
            hbox({
                text(" Login Screen ") | center | bold,
            }) | border,

            // Username input
            vbox({
                text("Username:"),
                hbox({
                    input_username->Render() | flex,
                }) | border,
            }),

            // Password input
            vbox({
                text("Password:"),
                hbox({
                    input_password->Render() | flex,
                }) | border,
            }),

            // Buttons
            hbox({
                login_button->Render(),
                quit_button->Render(),
            }),

            // Error message
            login_failed ?
                text("Invalid username or password!") | color(Color::Red) | center
                : text("")
        }) | border | size(WIDTH, LESS_THAN, 50) | center;
    });

    // Run the interactive screen
    auto screen = ScreenInteractive::TerminalOutput();
    screen.Loop(renderer);

    return 0;
}

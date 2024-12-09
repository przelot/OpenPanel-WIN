#include <iostream>

#ifdef __linux__
    char clear_screen_command[6] = "clear";
#elif _WIN32 or _WIN64
    char clear_screen_command[4] = "cls";
#else
    std::cout << "Undefined operating system" << std::endl;
    return 0;
#endif

void clear_screen() {
    system(clear_screen_command);
}

void blankline() {
    std::cout << '\n';
}

// ! Only functions above allowed in functions bellow !

void config() {

}

void hardware_info() {

}

void selftest() {

}

void socket_server() {

}

void main_display() {

}

int main(int argc, char const *argv[])
{
    int command;
    // Main function
    clear_screen();
    std::cout << "Panel" << std::endl;
    blankline();
    // Selftest
    selftest();
    // Wait for user input to continue
    do {
        std::cout << "Press enter to continue..." << std::endl;
    } while (std::cin.get() != '\n');
    // Main menu
    clear_screen();
    while (command != 99) {
        std::cout << "> ";
        if (!(std::cin >> command)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            clear_screen();
            std::cout << "Invalid argument" << std::endl;
            blankline();
            continue;
        }
        switch (command) {
            case 0:
                config();
                break;
            case 1:
                hardware_info();
                break;
            case 2:
                main_display();
                break;
            case 3:
                socket_server();
                break;
            case 99:
                std::cout << "Exit" << std::endl;
                return 0;
                break;
            default:
                clear_screen();
                std::cout << "Invalid argument" << std::endl;
                blankline();
                break;
        }
    }
}
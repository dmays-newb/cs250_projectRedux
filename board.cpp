#include <iostream>
#include "board.h"

int ValidCol() {
    int i = -1;
    while (i < 0 || i > 10) {
        std::cout << "Enter the column to build in (0-10)"
        << "..or Enter 11 to go back: "
        << std::endl;
        std::cin >> i;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Try again" << std::endl;
            i = -1;
        }
        else if (i < 0 || i > 10) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Try again" << std::endl;
        }
    }
    return i;
}

int ValidRow() {
    int i = -1;
    while (i < 0 || i > 11) {
        std::cout << "Enter the row to build in (0-10)"
        << "..or Enter 11 to go back: "
        << std::endl;
        std::cin >> i;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Try again" << std::endl;
            i = -1;
        }
        else if (i < 0 || i > 11) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Try again" << std::endl;
        }
    }
    return i;
}
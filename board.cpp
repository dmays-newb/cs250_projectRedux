#include <iostream>
#include "board.h"
#include "utils.h"

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


#ifdef DEBUG_BOARD
    void Board::DebugBoard(int var, int line) {
        std::cerr << "File: " << __FILE__;
        DebugOut(var, line);
    }
#else
    void Board::DebugBoard(int var, int line) { var = 0; }
#endif


Board::Board(Player &p1, Player &p2, int &t, int rc[]) {
    playerOne = &p1;
    playerTwo = &p2;
    turns = &t;
    resourceChanges = rc;

    DebugBoard(*turns, __LINE__);
    DebugBoard(resourceChanges[0], __LINE__);
}

bool EnoughResources(int rc[], int count) {
    //Call 
}

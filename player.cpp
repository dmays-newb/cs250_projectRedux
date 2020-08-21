#include <iostream>
#include "player.h"

void TradeOutMessage() {
    std::cout << "Trade for (b,h,o,s,w)"
        << "..or Enter x to go back: ";
}

void TradeForMessage() {
    std::cout << "Trade in three of yours (b,h,o,s,w)"
    << "..or Enter x to go back: ";
}


// char ValidateChar(bool ThisIsPayment) {
//     char c[100];
//     bool valid = false;
//     while (valid == false) {
//         (ThisIsPayment) ? TradeOutMessage():TradeForMessage();
//         std::cin >> c;
//         std::cin.clear();
//         std::cin.ignore(100, '\n');
//         if (c[0] == 'b' || c[0] == 'h' || c[0] == 'o' || c[0] == 'x' 
//         || c[0] == 's'  ||  c[0] == 'w' && isspace(c[0]) == 0)
//             break;
//     }
//     return c[0];
// }

    //  int* GetWages() { return wages ; }

Player::Player(int &t, int rc[]) {
    turns = &t;
    resourceChanges = rc;
    
    for (int i = 0; i < 5; i++) {
        resources[i] = 0;
        wages[i] = 0;
    }
    
}
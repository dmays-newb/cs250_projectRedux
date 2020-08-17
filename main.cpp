#include <iostream>
#include "utils.h"
#include "gamestatus.h"


#ifdef DEBUG_MAIN

int main(int argc, char *argv[]) {
    int turns = 0;
    int player1xScore = 0;
    int player2yScore = 0;
    int resourceChanges[6] = {0};

    int num[argc-1];
    for (int i = 1; i < argc; i++)
        num[i] = ConvertToInt(argv[i]);

    GameStatus status(player1xScore, player2yScore, turns, resourceChanges); 

    return 0;
}

#else

//official main
int main() {
    int turns = 0;
    int player1xScore = 0;
    int player2yScore = 0;
    int resourceChanges[6] = {0};

    GameStatus status(player1xScore, player2yScore, turns, resourceChanges); 

    return 0;
}

#endif


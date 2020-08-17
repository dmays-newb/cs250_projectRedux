#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "gamestatus.h"
#include "board.h"
#include "player.h"
#include "gameloop.h"



#ifdef DEBUG_MAIN

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int turns = 1;
    int player1xScore = 0;
    int player2yScore = 0;
    int resourceChanges[6] = {-3, 0, 1, 2, 3, 0};
    

    int num[argc-1];
    for (int i = 1; i < argc; i++)
        num[i] = ConvertToInt(argv[i]);

    GameStatus status(player1xScore, player2yScore, turns, resourceChanges); 
    Board board;
    Player p1x;
    Player p2y;

    // Debug2File(turns, __LINE__);
    // GameLoop(status, board, p1x, p2y);

    char c = ValidateChar(0);

    return 0;
}

#else

//official main
int main() {
    srand(time(NULL));
    int turns = 1;
    int player1xScore = 0;
    int player2yScore = 0;
    int resourceChanges[6] = {0};

    Board board;
    Player p1x;
    Player p2y;
    GameStatus status(player1xScore, player2yScore, turns, resourceChanges); 
    GameLoop(status, board, p1x, p2y);

    return 0;
}

#endif

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
    int turns;
    int player1xScore;
    int player2yScore;
    int resourceChanges[6];
    
    //manage CLAs
    int num[argc-1];
    for (int i = 1; i < argc; i++)
        num[i] = ConvertToInt(argv[i]);

    do {
        turns = 1;
        player1xScore = 1;
        player2yScore = 2;

        for (int i = 0; i < 6; i++) 
            resourceChanges[i] = 0;

    GameStatus status(player1xScore, player2yScore, turns, resourceChanges); 
    Board board(player1xScore, player2yScore, turns, resourceChanges);
    Player p1x;
    Player p2y;

    status.PrintScores();

    GameLoop(status, board, p1x, p2y);
       

    } while (PlayAgain());

    // Debug2File(turns, __LINE__);


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

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "gamestatus.h"
#include "board.h"
#include "player.h"



#ifdef DEBUG_MAIN

int main(int argc, char *argv[]) {
    int turns = 0;
    int player1xScore = 0;
    int player2yScore = 0;
    int resourceChanges[6] = {-3, 0, 1, 2, 3, 0};
    void GameLoop(GameStatus, Board, Player, Player); 
    

    int num[argc-1];
    for (int i = 1; i < argc; i++)
        num[i] = ConvertToInt(argv[i]);

    GameStatus status(player1xScore, player2yScore, turns, resourceChanges); 
    //initialize players and board here
    Board board;
    Player p1x;
    Player p2y;

    Debug2File(turns, __LINE__);


    GameLoop(status, board, p1x, p2y);

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

    void GameLoop(GameStatus stats, Board board, Player x1, Player y2) {
        srand(time(NULL));
        int random;


        do {
            random = rand() % 2;
            if (random == 0)
                stats.IncrementP2Score();
            else
                stats.IncrementP1Score();

            stats.IncrementTurns();
            DebugOut(stats.GetTurns(), __LINE__);
            PrintLine(15);

        } while (!stats.GameOver());
        
        
        int winner;

        winner = WhichPlayer(stats.GetTurns());

        std::cout << "Player number " << winner
            << " has won the game!" << std::endl;



    }
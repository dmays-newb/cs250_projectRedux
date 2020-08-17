#include <stdlib.h>
#include <iostream>
#include "gameloop.h"
#include "utils.h"

void GameLoop(GameStatus stats, Board board, Player x1, Player y2) {
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
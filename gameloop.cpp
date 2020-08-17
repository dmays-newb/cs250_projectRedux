#include <stdlib.h>
#include <iostream>
#include "gameloop.h"
#include "utils.h"

void GameLoop(GameStatus stats, Board board, Player x1, Player y2) {

        // odd number of turns at end means p1x wins
        // even for player 2
        do {

            // exit when a player's score is over 6
        } while (!stats.GameOver());
        
}
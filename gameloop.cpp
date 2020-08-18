// #include <stdlib.h>
#include <iostream>
#include "gameloop.h"
#include "utils.h"


void NewGamePrompt() {
    std::cout << "Would you like to play again? (y/n) ";
}

bool PlayAgain() {
    bool newGame;
    char YesNo[4] = {'y','n','Y','N'};
    int playAgain;

    NewGamePrompt();
    playAgain = CharInputAndCheck(YesNo, 4);
    if (playAgain % 2 == 0)
        return true;
    else
        return false;
    
}

void GameLoop(GameStatus stats, Board board, Player x1, Player y2) {

        // odd number of turns at end means p1x wins
        // even for player 2
    do {
        // for (int i = 0; i < 6; i++)
            // stats.IncrementP1Score();

        // exit when a player's score is over 6
    } while (!stats.GameOver());



}
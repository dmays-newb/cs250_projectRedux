// #include <stdlib.h>
#include <iostream>
#include "gameloop.h"
#include "gamestatus.h"
#include "utils.h"
#include "board.h"
#include "player.h"



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

void GameLoop() {
    int turns = 1;
    int player1xScore = 1;
    int player2yScore = 2;
    int resourceChanges[5];
    int activePlayer = 1;
    int choice = 0;

    for (int i = 0; i < 5; i++) 
        resourceChanges[i] = 0;

    GameStatus stats(player1xScore, player2yScore, turns, resourceChanges); 
    Player p1x(turns, resourceChanges);
    Player p2y(turns, resourceChanges);
    Board board(p1x, p2y, turns, resourceChanges);

    // stats.PrintScores();
    // board.DebugBoard(-1, __LINE__);

        // odd number of turns at end means p1x wins
        // even for player 2
    do {
        // for (int i = 0; i < 6; i++)
            // stats.IncrementP1Score();
        activePlayer = WhichPlayer(turns);
        choice = ActionChoice(activePlayer);

        switch (choice)
        {
        case /* constant-expression */:
            /* code */
            break;
        
        default:
            break;
        }
        

        //Start with action choice
            //action choice returns an int
            //use a switch to choose what to do: increment turn, increment score and turn, start turn over
            //


        // exit when a player's score is over 6
    } while (!stats.GameOver());



}
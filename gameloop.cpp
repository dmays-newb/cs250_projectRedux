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

int RunTurn(int choice, Player &player) {

    int endOfTurnAction = 0;
    switch (choice)
    {
    case 1: //build
        endOfTurnAction = RequestBuild(); //road =1; settle =2; invalid =0;
        //if invalid -> restart loop without incrementing score or turn
        break;
    case 2: //trade
        endOfTurnAction = RequestTrade(); //valid trade = 1; invalid = 0        
        break;
    default: //pass -- no change to endOfTurnAction
        break;
    }
    return endOfTurnAction;
}

void EndOfTurnActions(int option, GameStatus &stats) {
    switch (option)
    {
    case 1: //increment turns 
        /* code */
        break;
    case 2: //increment turns and score
        //code
        break;
    default: //no change -- restart turn
        break;
    }
}

void GameLoop() {
    int turns = 1;
    int player1xScore = 1;
    int player2yScore = 2;
    int resourceChanges[5];
    int activePlayer = 1;
    int choice = 0;
    int turnResult = 0;

    for (int i = 0; i < 5; i++) 
        resourceChanges[i] = 0;

    GameStatus stats(player1xScore, player2yScore, turns, resourceChanges); 
    Player player1(turns, resourceChanges);
    Player player2(turns, resourceChanges);
    Board board(player1, player2, turns, resourceChanges);

    // stats.PrintScores();
    // board.DebugBoard(-1, __LINE__);

        // odd number of turns at end means player1 wins
        // even for player 2
    do {
        // for (int i = 0; i < 6; i++)
            // stats.IncrementP1Score();
        activePlayer = WhichPlayer(turns);
        choice = ActionChoice(activePlayer);

        if (activePlayer == 1)
            turnResult = RunTurn(choice, player1);
        else 
            turnResult = RunTurn(choice, player2);

        EndOfTurnActions(turnResult, stats);
        

        //Start with action choice
            //action choice returns an int
            //use a switch to choose what to do: increment turn, increment score and turn, start turn over
            //


        // exit when a player's score is over 6
    } while (!stats.GameOver());



}
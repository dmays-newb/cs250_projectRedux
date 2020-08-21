#include <iostream>
#include "gamestatus.h"
#include "utils.h"

#ifdef DEBUG_GAMESTATUS
    void GameStatus::DebugStatus(int var, int line) {
        std::cerr << "File: " << __FILE__;
        DebugOut(var, line);
    }
#else
    void GameStatus::DebugStatus(int var, int line) { var = 0; }
#endif

GameStatus::GameStatus(int &p1, int &p2, int &t, int rc[]) {
    player1xScore = &p1;
    player2yScore = &p2;
    turns = &t;
    resourceChanges = rc;

    DebugStatus(*player1xScore, __LINE__);
    DebugStatus(*player2yScore, __LINE__);
    DebugStatus(*turns, __LINE__);
    DebugStatus(resourceChanges[0], __LINE__);
}

bool GameStatus::GameOver() {
    if (*player1xScore >= 6 || *player2yScore >= 6)
        return true;
    else 
        return false;
}

void GameStatus::PrintScores() {
    PrintLine(30);
    
    for (int i = 0; i < 2; i++) {
        std::cout << "Player #" << i + 1 
            << " score: ";
        if (i == 0)
            PrintScore1x();
        else
            PrintScore2y();
        PrintLine();
    }
}

void GameStatus::WinningStatement() {
    int winner;
    winner = WhichPlayer(*turns);

    std::cout << "Player number " << winner
        << " has won the game!"
        << '\n' << "Player1 Score: " << *player1xScore
        << '\n' << "Player2 Score: " <<  *player2yScore
        << '\n' << "Turns: " << *turns
        << std::endl;

}
void ActionPrompt(int player) {
    std::cout << "Player " << player << " Select Move:"
        << "\t1 (Build)\t2 (Trade)\t3 (Pass)" << std::endl;

}

int ActionChoice(int player) {
    int options[3] = {1, 2, 3}; 
    int choice = -1;

    do {
        ActionPrompt(player);
        VariableMatch(choice, options, 3);

    } while (choice <= 0 || choice >= 4);

     
}
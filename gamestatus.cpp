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
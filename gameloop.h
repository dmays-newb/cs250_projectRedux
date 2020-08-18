#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "player.h"
#include "board.h"
#include "gamestatus.h"

void GameLoop(GameStatus, Board, Player, Player);

bool PlayAgain();

#endif // !GAMELOOP_H
#ifndef BOARD_H
#define BOARD_H
#include "player.h"

    class Board {
        friend class Player;   
        private:
            int* player1xScore;
            int* player2yScore;
            int* turns;
            int* resourceChanges;

        public:
            Board(int &p1, int &p2, int &t, int rc[]);
            void DebugBoard(int var, int line);
    };

#endif
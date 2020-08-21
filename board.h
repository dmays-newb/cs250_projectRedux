#ifndef BOARD_H
#define BOARD_H
#include "player.h"

    class Board {
        friend class Player;   
        private:
            int* turns;
            int* resourceChanges;
            Player* playerOne;
            Player* playerTwo;

        public:
            Board(Player &p1, Player &p2, int &t, int rc[]);
            void DebugBoard(int var, int line);
    };

#endif
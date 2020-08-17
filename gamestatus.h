

#ifndef GAMESTATUS_H
#define GAMESTATUS_H

class GameStatus {
    private:
        int actionChoice { actionChoice = 0 };
        int* player1xScore;
        int* player2yScore;
        int* turns;
        int* resourceChanges;

    public:
        GameStatus(int &, int &, int &, int []);
        void DebugStatus(int, int);
        int GetTurns() {return *turns ;}
        int GetP1Score() {return *player1xScore ;}
        int GetP2Score() {return *player2yScore ;}
        int GetActionChoice() {return actionChoice ;}
        void IncrementTurns() { *turns += 1 ;}
        void IncrementP1Score() { *player1xScore += 1 ;}
        void IncrementP2Score() { *player2yScore += 1 ;}
        void PrintScore1x() { std::cout << *player1xScore ; }
        void PrintScore2y() { std::cout << *player2yScore ; }
        void PrintTurns() { std::cout << *turns ; }
};

#endif // !GAMESTATUS_H
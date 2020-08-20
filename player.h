
#ifndef PLAYER_H
#define PLAYER_H

    class Player {
        private:
            int* turns;
            int* resourceChanges;
            int resources[6];
            int wages[6];
        public:
            Player(int &t, int rc[]);
            //bool tradeReq();
            //void UpdateWages();
            //void UpdateResources(); //use pre-existing array update tool(s)
            int* GetResources() { return resources ; }
            bool EnoughResources(/*Options here*/); //Use for trades, validating builds; 
            //use WhichPlayer() to determine which one..?
    };

    int* GetWages();

    // char ValidateChar(bool ThisIsPayment);

#endif // !PLAYER_H
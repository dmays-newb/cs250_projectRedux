#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "gameloop.h"
#include "utils.h"



#ifdef DEBUG_MAIN

int main(int argc, char *argv[]) {
    srand(time(NULL));
    
    //manage CLAs
    int num[argc-1];
    for (int i = 1; i < argc; i++)
        num[i] = ConvertToInt(argv[i]);

    do {

    GameLoop();

    } while (PlayAgain());

    return 0;
}

#else

//official main
int main() {
    srand(time(NULL));

    GameLoop();

    return 0;
}

#endif

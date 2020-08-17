#include <iostream>


int turns = 0;
int scores[2] = {0};
int resourceChanges[6] = {0};


#ifdef DEBUG_MAIN
int ConvertToInt(char* c) {
    int num = atoi(c);
    return num;
}

int main(int argc, char *argv[]) {

    int num[argc-1];
    for (int i = 1; i < argc; i++)
        num[i] = ConvertToInt(argv[i]);

    //std::cerr << num[1] << '-' << num[2];
    
    return 0;
}

#else

//official main
int main() {

    return 0;
}

#endif
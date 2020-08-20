// debugging, conversion, and input/output utlities

#include <iostream>
#include <iomanip>
#include <fstream>

int ConvertToInt(char* c) {
    int num = atoi(c);
    return num;
}

void DebugOut(int var, int line) { 
       std::cerr << " Line: " << line
           << "\nVariable = "
           << var << std::endl;
}


void DebugOut(std::ostream &file, int var, int line) {
     file << "Line: " << line
           << "\nVariable = "
           << var << std::endl;
}

void PrintLine(std::ostream &file, int n) {
    file << std::setw(n) << std::setfill('-');
    file << std::setw(0) << std::setfill(' ');
}

//Print line of n length
void PrintLine(int n) {
    std::cout << '\n' << std::setw(n) << std::setfill('-') 
        << '\n';
    std::cout << std::setw(0) << std::setfill(' ');
}

//Print line of 30 length
void PrintLine() {
    int n = 30;
    std::cout << '\n' << std::setw(n) << std::setfill('-') 
        << '\n';
    std::cout << std::setw(0) << std::setfill(' ');
}

int WhichPlayer(int turns) {
    if (turns % 2 != 0)
        return 1;
    else 
        return 2;
}

void Debug2File(int var, int line) {

    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);


    std::ofstream out;
    out.open("DebugFile.txt", std::ios::app);
    out <<  asctime(timeinfo);
    out << "----Begin----" << std::endl;
    DebugOut(out, var, line);
    out << "----End----" << '\n' << std::endl;


}

void AnyKey() {
    char any;
    std::cout << "Press any key and Return to continue.";
    std::cin >> any;
}

void Reset() {
    #ifdef LINUX
        system("clear");
    #else
        system("CLS");
    #endif
}

void InvalidEntry() {
    std::cout << "Entry out of range. Try again: " << std::endl;
}

template <class T>
void InvalidEntry(T options[], int count) {
    std::cout << "Entry out of range."
        << "\nTry again with one of these options: " << std::endl;

    for (int i = 0; i < count; i++) {
        std::cout << options[i] << ' ';
    } 
    
}

void PrintNumRow(int n) {       
    std::cout << ' ';
    for (int k = 0; k <= n; k++) {
        std::cout << std::right << std::setw(3)
            << std::setfill(' ') << k;
    }
    std::cout << '\n' << std::endl;
}


template <class T>
T GetInput(T var) {  
    std::cout << std::flush;

    // std::cerr << "Error output GetInput. Line: " 
    //     << __LINE__ << std::endl;

    if (std::cin >> var) 
        return var;
    else {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Try again: " << std::endl;
        return GetInput(var);
    }
}

template <class T>
bool ValidRange(T input, T min, T max) {
    bool valid;
    (!(min <= input <= max)) ? valid=false:valid=true;
    return valid;
}

//Update the template for this
template <class T>
int VariableMatch(T input, const T options[], int count) {
    T in = input;
    // std::cerr << "Error output VariableMatch. "
    //     << " Line: " << __LINE__ 
    //     << " Input: " << input
    //     << " Count: " << count << std::endl;
    int attempts = 0;
    while (attempts < 10) {

        for (int i = 0; i < count; i++) {
            if (in == options[i])
                return i;
        }
    attempts++;
    InvalidEntry(options, count);
    in = GetInput(input);
    }

    return -1;
}
//Create/update this template for later use
int CharInputAndCheck(const char options[], int count) {
    char input;
    int playerChoice;
        input = GetInput(input);
        playerChoice = VariableMatch(input, options, count);


    return playerChoice;
}

void UpdateIntArray(const int input[], int updateThis[], int count) {
    for (int i = 0; i < count; i++) {
        updateThis[i] += input[i];
    }
        
}


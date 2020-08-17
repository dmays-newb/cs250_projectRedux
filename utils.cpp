// debugging, conversion, and input/output utlities

#include <iostream>
#include <iomanip>

int ConvertToInt(char* c) {
    int num = atoi(c);
    return num;
}

void DebugOut(int var, int line) { 
       std::cerr << " Line: " << line
           << "\nVariable = "
           << var << std::endl;
}

void PrintLine(int n) {
    std::cout << '\n' << std::setw(n) << std::setfill('-') << '\n';
}
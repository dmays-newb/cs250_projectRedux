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

void PrintLine(int n) {
    std::cout << '\n' << std::setw(n) << std::setfill('-') 
        << '\n';
    std::cout << std::setw(0) << std::setfill(' ');
}

void PrintLine(std::ostream &file, int n) {
    file << std::setw(n) << std::setfill('-');
    //file << std::setw(0) << std::setfill(' ');
}

int WhichPlayer(int turns) {
    if (turns % 2 == 0)
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

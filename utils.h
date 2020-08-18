#ifndef UTILS_H
#define UTILS_H
 
int ConvertToInt(char* c);

void DebugOut(int var, int line);

void PrintLine(int n);

int WhichPlayer(int turns);

void Debug2File(int var, int line);

void AnyKey();

void Reset();

void InvalidEntry();

void PrintNumRow(int n);

template <class T>
T GetInput(T var);

template <class T>
bool ValidRange(T input, T min, T max);

template <class T>
int VariableMatch(T input, const T options[], int count);

int CharInputAndCheck(const char options[], int count);

void UpdateIntArray(const int input[], int updateThis[], int count);

#endif // 

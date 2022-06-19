#pragma once
int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int &startValue, int increment, int numTimes);
void swapNumbers(int &firstNumber, int &secondNumber);
// Noen måte å få denne inn i utilites?
struct Student {
    string name; 
    string studyProgram; 
    int age;
};
void printStudent(string name, string studyProgram, int age);
string isInProgram(string studyProgramInput, string studyProgramToCompare);
string randomizeString(int length, char lowerLimit, char upperLimit);
string readInputToString(int n, char lowerLimit, char upperLimit);
int countChar(string word, char character);
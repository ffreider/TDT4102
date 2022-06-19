#include "std_lib_facilities.h"
#include "utilities.h"  
#include<iostream>
#include <charconv>    
// OPPGAVE 1
// returnerer startvalue + (increment*numtimes)
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}
void incrementByValueNumTimesRef(int &startValue, int increment, int numTimes) {
        for (int i = 0; i < numTimes; i++) {
            startValue += increment;
    }
}
// Burde bruke referanse hvis den skal endre tallene etter funksjonen er kalt. 
void swapNumbers(int &firstNumber, int &secondNumber) {
    int one = firstNumber;
    int two = secondNumber;
    firstNumber = two;
    secondNumber = one;
}

// OPPGAVE 2
void printStudent(string name, string studyProgram, int age) {
    Student student {name, studyProgram, age};
    cout << "Navn er: " << student.name << ", h*n studerer " << studyProgram << " og er " << age << " gammel.\n"; 
}
string isInProgram(string studyProgramInput, string studyProgramToCompare) {
    if (studyProgramInput == studyProgramToCompare) {
        return "Samme studie";
    } else {
        return "Ikke samme studie";
    }
}
// e) kan vel fjerne #include "utilities.h" fra tests.h?

// OPPGAVE 3
string randomizeString(int length, char lowerLimit, char upperLimit) {
    string randomString = "";
    for (int i = 0; i < length; i++) {
        int num = rand() % (int(upperLimit)-int(lowerLimit)+1)+int(lowerLimit);
        randomString = randomString + to_string(char(num));
    }
    return randomString;
}

string readInputToString(int n, char lowerLimit, char upperLimit) {
    string guess;
    cout << "Skriv inn " << n << " bokstaver mellom " << lowerLimit << " og " << upperLimit << endl;
    cin >> guess;
    while (int(guess.length()) != n) {
        cout << "Feil antall bokstaver";
        cout << "Skriv inn " << n << " bokstaver mellom " << lowerLimit << " og " << upperLimit << endl;
        cin >> guess; 
    }
    for_each(guess.begin(), guess.end(), [](char & c) {
    	c = ::toupper(c);
	});
    return guess;
}

int countChar(string word, char character) {
    int x = 0;
    for (int i = 0; i < int(word.length()); i++) {
        if (word[i] == character) {
            x += 1;
        }
    }
    return x;
}






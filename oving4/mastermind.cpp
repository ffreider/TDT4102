#include "std_lib_facilities.h"
#include "utilities.h"
#include "masterVisual.h"


int checkCharactersAndPosition(string guess, string code) {
    int correct = 0;
    for (int i = 0; i < int(guess.length()); i++) {
        if (guess[i] == code[i]) {
            correct += 1;
        }
    }
    return correct;
}

int checkCharacters(string guess, string code) {
    int correct = 0;
    sort(guess.begin(), guess.end());
    for (int i = 0; i < int(guess.length()); i++) {
        if (i != 0) {
            if (guess[i] != guess[i-1]) {
                correct += count(code.begin(), code.end(), guess[i]);
            }
        } else {
            correct += count(code.begin(), code.end(), guess[i]);
        }
    }
    return correct;
}

// skjønte ikke helt forskjellen på const og constexpr
void playMastermind() { 
    MastermindWindow mwin{900, 20, 500, 500, 4, "Mastermind"};
    mwin.setCodeHidden(false);
    constexpr int size = 4;
    int attempts = 6;
    int n = 0;
    string code = randomizeString(size, 'A', 'F');
    string guess;
    guess = mwin.getInput(4, 'A', 'F');
    while (size > checkCharactersAndPosition(guess, code)) {
        if (n == attempts-1) {
            break;
        }
        cout << "Antall korrekte bokstaver: " << checkCharacters(guess, code) 
        << "\nAntall korrekte bokstaver på rett plass: " << checkCharactersAndPosition(guess, code) <<"\nPrøv igjen: \n";
        cout << "svaret er " << code << endl;
        guess = mwin.getInput(4, 'A', 'F') ;
        n += 1;
        addFeedback(mwin, checkCharacters(guess, code), checkCharactersAndPosition(guess, code));
        mwin.redraw();
    }
    if (n == attempts-1) {
        cout << "For mange forsøk. Du tapte.\n";
    } else {
        cout << "du vant\n" << code;
    }
}
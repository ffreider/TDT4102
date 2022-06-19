#include "std_lib_facilities.h"
#include "Card.h"

string Card::suitToString(Suit s) {
    switch(int(s)) {
        case 0:     
            return "Clubs";
        case 1: 
            return "Diamonds";
        case 2: 
            return "Hearts";
        case 3: 
            return "Spades";
    }
    return "Switch Failed";
}
string Card::rankToString(Rank r) {
    switch(int(r)) {
        case 2: 
            return "Two";
        case 3: 
            return "Three";
        case 4: 
            return "Four";
        case 5: 
            return "Five";
        case 6: 
            return "Six";
        case 7: 
            return "Seven";
        case 8: 
            return "Eight";
        case 9: 
            return "Nine";
        case 10: 
            return "Ten";
        case 11: 
            return "Jack";
        case 12: 
            return "Queen";
        case 13: 
            return "King";
        case 14: 
            return "Ace";
    }
    return "Switch Failed";
}

































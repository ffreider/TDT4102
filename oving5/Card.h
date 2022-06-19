#pragma once
#include "std_lib_facilities.h"
class Card {
public:
    enum class Suit {clubs, diamonds, hearts, spades};
    enum class Rank {two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};
    Card(Rank rank, Suit suit) {
        this->rank = rank;
        this->suit = suit;
    }
    Rank getRank() {
        return rank;
    }
    Suit getSuit() {
        return suit;
    }
    string toString() {
        return rankToString(rank) + " of " + suitToString(suit);
    }
private:
    string suitToString(Suit s);
    string rankToString(Rank r);
    Rank rank;
    Suit suit;
};

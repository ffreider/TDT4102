#pragma once
#include "std_lib_facilities.h"
#include "Card.h"

class CardDeck {
public:
    CardDeck();
    void swap(int index1, int index2);
    void print();
    void shuffle();
    Card drawCard();
private:
    vector<Card> cards;
};



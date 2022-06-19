#pragma once
#include "std_lib_facilities.h"
#include "CardDeck.h"


class Blackjack {
public:
    bool isAce(Card card);
    int getCardValue(Card card);
    int getHandScore(vector<Card> vec);
    bool askPlayerDrawCard();
    void drawPlayerCard();
    void drawDealerCard();
    void playGame();
private:
    CardDeck deck;
    vector<Card> playerHand;
    vector<Card> dealerHand;
    int playerHandSum;
    int dealerHandSum;
};
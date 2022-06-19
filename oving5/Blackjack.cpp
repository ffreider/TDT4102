#include "Blackjack.h"
#include "CardDeck.h"
#include "Card.h"
#include "std_lib_facilities.h"

bool Blackjack::isAce(Card card) {
    if (static_cast<int>(card.getRank()) == 14) {
        return true;
    } else {
        return false;
    }
}
int Blackjack::getCardValue(Card card) {
    vector<int> ace;
    if (isAce(card)){
        return 11;
   } else if (static_cast<int>(card.getRank()) > 9){
       return 10;
   } else {
       return static_cast<int>(card.getRank());
   }
}   
int Blackjack::getHandScore(vector<Card> vec) {
    int sum = 0;
    for (int card = 0; card < static_cast<int>(vec.size()); card++) {
        sum += getCardValue(vec[card]);
    }
    return sum;
}
bool Blackjack::askPlayerDrawCard() {
    string answer;
    cout << "Do you want to draw another card? (Y/N)" << endl;
    cin >> answer;
    if (answer == "Y") {
        return true;
    } else {
        return false;
    }
}
void Blackjack::drawPlayerCard() {
    Card newCard = deck.CardDeck::drawCard();
    playerHand.push_back(newCard);
    playerHandSum += getCardValue(newCard);
}
void Blackjack::drawDealerCard() {
    Card newCard = deck.CardDeck::drawCard();
    dealerHand.push_back(newCard);
    dealerHandSum += getCardValue(newCard);
}
void Blackjack::playGame() {
    deck.shuffle();
    bool winner = false;
    while (winner == false) {
        drawPlayerCard();
        cout << "Player: " << getHandScore(playerHand) << endl;
        drawDealerCard();
        cout << "Dealer: " << getHandScore(dealerHand) << endl;
        drawPlayerCard();
        cout << "Player: " << getHandScore(playerHand) << endl;
        if (getHandScore(dealerHand) > 9) {
            drawDealerCard();
            cout << "Dealer: " << getHandScore(dealerHand) << endl;
        } else {
            drawDealerCard();
        }
        if (getHandScore(dealerHand) == 21) {
            cout << "BLACKJACK! DEALER WINS" << endl;
            winner = true;
            break;
        }
        if (getHandScore(playerHand) == 21) {
            cout << "BLACKJACK! PLAYER WINS" << endl;
            winner = true;
            break;
        }
        bool draw = askPlayerDrawCard();
        while (draw == true) {
            drawPlayerCard();
            cout << "Player: " << getHandScore(playerHand) << endl;
            if (getHandScore(playerHand) > 21) {
                cout << "DEALER WINS. TOO HIGH" << endl;
                winner = true;
                break;
            } else if (getHandScore(playerHand) == 21) {
                cout << "BLACKJACK! PLAYER WINS." << endl;
                winner = true;
                break;
            } else {
                draw = askPlayerDrawCard();
            }
        }
        while (getHandScore(dealerHand) < 16) {
            cout << "Dealer: " << getHandScore(dealerHand) << endl;
            drawDealerCard();
            if (getHandScore(dealerHand) == 21) {
                cout << "BLACKJACK! DEALER WINS." << endl;
                winner = true;
                break;
            } else if (getHandScore(dealerHand) > 21) {
                cout << "PLAYER WINS! DEALER TOO HIGH." << endl;
                winner = true;
                break;
            }
        }
        cout << "Dealer: " << getHandScore(dealerHand) << endl;
        if (getHandScore(playerHand) == getHandScore(dealerHand)) {
            cout << "SPLIT.";
            winner = true;
        } else if (getHandScore(playerHand) < getHandScore(dealerHand)) {
            cout << "DEALER WINS.";
            winner = true;
        } else if (getHandScore(playerHand) < 21) {
            cout << "PLAYER WINS.";
            winner = true;
        } else {
            winner = true;
            break;
        }
    }
}




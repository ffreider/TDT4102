#include "CardDeck.h"


CardDeck::CardDeck() {
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 2; rank <= 14; rank++) {
            cards.push_back(Card {static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit)});
        }
    }              
}
void CardDeck::swap(int index1, int index2) {
    Card tempCard1 = cards[index1];
    Card tempCard2 = cards[index2];

    cards[index1] = tempCard2;
    cards[index2] = tempCard1;
}
void CardDeck::print() {
    for (int card = 0; card < static_cast<int>(cards.size()); card++) {
        cout << cards[card].toString() << endl;
        
    }
}
void CardDeck::shuffle() {
    int r1;
    int r2;
    for (int i = 0; i < 500; i++) {
        r1 = rand() % static_cast<int>(cards.size());
        r2 = rand() % static_cast<int>(cards.size());
        swap(r1, r2);
    }

}
Card CardDeck::drawCard() {
    Card temp = cards[cards.size()-1];
    cards.pop_back();
    return temp;
}








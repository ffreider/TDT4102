#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"
#include "std_lib_facilities.h"

int main()
{
	srand(unsigned(time(nullptr)));
	Blackjack test;
	test.playGame();
	return 0;
}
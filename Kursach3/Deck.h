#pragma once
#include "Cards.h"
#include <vector>

class Deck  {
private:
	int trump_suit;
	std::vector <Cards> deck;
public:
	friend class Cards;
	Deck(int);
	Cards get_card_out(int);
	void get_card(Deck&, int);
	void deck_init();
	void shuffle();
	void trump_init();
};

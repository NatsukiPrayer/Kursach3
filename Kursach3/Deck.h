#pragma once
#include "Cards.h"
#include <vector>

class Deck : public Cards {
private:
	int trump_suit;
	std::vector <Cards> deck;
public:
	friend class Cards;
	Deck();
	void deck_init();
	void shuffle();
	void trump_init();
};

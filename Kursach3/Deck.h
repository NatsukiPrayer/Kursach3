#pragma once
#include "Cards.h"
#include <vector>

class Deck : public Cards {
private:
	std::vector <Cards> deck;
public:
	void deck_init();
	void shuffle();
};

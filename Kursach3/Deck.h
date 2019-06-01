#pragma once
#include "Cards.h"
#include <vector>

class Deck  {
private:
	int trump_suit;
	std::vector <Cards> deck;
public:
	int get_size_of_deck();
	friend class Cards;
	Deck();
	Cards get_card_out(int);
	int get_trump();
	void deck_info();
	void card_out(int);
	void get_card(Deck, int);
	void deck_init();
	void shuffle();
	void trump_init();
};

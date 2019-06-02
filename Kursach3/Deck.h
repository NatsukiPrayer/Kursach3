#pragma once
#include "Cards.h"
#include <vector>

class Deck  {
private:
	std::vector <int> rang_collection;
	int trump_suit;
	std::vector <Cards> deck;
public:
	int get_size_of_deck();
	friend class Cards;
	Deck();
	Cards get_card_out(int);
	int get_trump();
	void rng_coll_init();
	void set_add_rng_coll(int);
	int get_rng_coll(int);
	void deck_info();
	void card_out(int);
	void get_card(Deck, int);
	void deck_init();
	void shuffle();
	void trump_init();
};

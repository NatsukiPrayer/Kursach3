#include "pch.h"
#include "Deck.h"
#include <algorithm>
#include <random>


/*void Deck::deck_init()
{
	std::vector <Cards> deck_;
	for (int i = 0; i < 9; i++) {
		deck_[i]=Cards(i, true, true);
	}
	for (int i = 8; i < 18; i++) {
		deck[i] = Cards((i - 9), true, false);
	}
	for (int i = 18; i < 27; i++) {
		deck[i] = Cards((i - 18), false, true);
	}
	for (int i = 27; i < 36; i++) {
		deck[i] = Cards((i - 27), false, false);
	}
	this->deck =
}*/

void Deck::shuffle()
{
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(this->deck), std::end(this->deck), rng);
}

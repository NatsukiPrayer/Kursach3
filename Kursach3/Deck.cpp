#include "pch.h"
#include "Deck.h"
#include <algorithm>
#include <random>


Deck::Deck()
{}

void Deck::deck_init()
{
	for (int i = 0; i < 9; i++) {
		this->deck.push_back(Cards(i, 0, false));
	}
	for (int i = 8; i < 18; i++) {
		this->deck.push_back(Cards((i - 9), 1, false));
	}
	for (int i = 18; i < 27; i++) {
		this->deck.push_back(Cards((i - 18), 2,false));
	}
	for (int i = 27; i < 36; i++) {
		this->deck.push_back(Cards((i - 27), 3, false));
	}
}
void Deck::shuffle()
{
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(this->deck), std::end(this->deck), rng);
}

void Deck::trump_init()
{
	int s = std::size(this->deck);
	for (int i=0; i<s; i++)
	 {
		if (this->deck.at(i).suit == this->trump_suit)
			this->deck.at(i).trump = true;
	}
}

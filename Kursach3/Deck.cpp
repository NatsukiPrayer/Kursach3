#include "pch.h"
#include "Deck.h"
#include <algorithm>
#include <random>


Deck::Deck(int n)
{
	deck.resize(n);
}

Cards Deck::get_card_out(int c)
{
	return deck.at(c);
}

void Deck::get_card(Deck& d1, int l)
{
	Cards *c = new Cards;
	c = &d1.deck.at(l+2);
	d1.deck.erase(d1.deck.begin()+l+2);
	this->deck.push_back(*c);
	delete c;
}

void Deck::deck_init()
{
	for (int i = 0; i < 9; i++) {
		this->deck.push_back(Cards(i, 0, false));
	}
	for (int i = 9; i < 18; i++) {
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
	for (int i = std::rand() % 100; i <= 100; i++) {
		for (int k = 0; k < i; k++)
			std::random_shuffle(std::begin(this->deck), std::end(this->deck));
	}
}

void Deck::trump_init()
{
	trump_suit = this->deck.at(0).suit;
	int s = std::size(this->deck);
	for (int i=0; i<s; i++)
	 {
		if (this->deck.at(i).suit == this->trump_suit)
			this->deck.at(i).trump = true;
	}
}

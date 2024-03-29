#include "pch.h"
#include "Deck.h"
#include <algorithm>
#include <random>


int Deck::get_size_of_deck()
{
	return deck.size();
}

Deck::Deck()
{}

Cards Deck::get_card_out(int c)
{
	return deck.at(c);
}

int Deck::get_trump()
{
	return trump_suit;
}

void Deck::rng_coll_init()
{
	for (int i = 0; i < 36; i++)
		set_add_rng_coll(deck.at(i).get_rang());
}

void Deck::set_add_rng_coll(int a)
{
	rang_collection.push_back(a);
}

int Deck::get_rng_coll(int d)
{
	if (d < rang_collection.size())
		return rang_collection.at(d);
}

void Deck::deck_info()
{
	for (int i = 0; i < deck.size(); i++) {
		std::cout << i << ". "; deck.at(i).info();
	}
}

void Deck::card_out(int p)
{
	if (p == 0) {
		deck.erase(deck.begin());
		rang_collection.erase(rang_collection.begin());
	}

	else {
		deck.erase(deck.begin() + p);
		rang_collection.erase(rang_collection.begin() + p);
	}
}

void Deck::get_card(Deck d1, int c)
{
	this->deck.push_back(d1.deck.at(c));
	this->rang_collection.push_back(d1.deck.at(c).get_rang());
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
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(this->deck), std::end(this->deck), rng);
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

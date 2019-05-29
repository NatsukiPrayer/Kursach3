#include "pch.h"
#include "Deck.h"
#include <algorithm>
#include <random>


void Deck::shuffle()
{
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(this->deck), std::end(this->deck), rng);
}

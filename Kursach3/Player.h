#pragma once
#include "Deck.h"
#include <string>
class Player {
private:
	std::string nick;
public:
	friend Deck;
};

#pragma once
#include "Deck.h"
#include <string>
class Player {
protected:
	std::string nick;
	bool alive;
public:
	Player(std::string n, bool a);
	virtual bool next_turn();
};

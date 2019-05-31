#pragma once
#include "Deck.h"
#include <string>
class Player {
protected:
	std::string nick;
	bool alive;
public:
	std::string get_name();
	Player(std::string n, bool a);
	virtual bool next_turn();
};

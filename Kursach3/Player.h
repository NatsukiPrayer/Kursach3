#pragma once
#include "Deck.h"
#include <string>
class Player {
protected:
	std::string nick;
	bool Human;
public:
	virtual bool next_turn();
};

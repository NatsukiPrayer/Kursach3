#pragma once
#include "Player.h"
#ifndef PLAYER_H
#define PLAYER_H

class Ai : public Player {
public:
	std::string get_name();
	Ai(std::string n, bool a);
	bool next_turn();
	void turn(Deck&, Deck&);
};

#endif // !PLAYER_H


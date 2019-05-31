#pragma once
#include "Player.h"
#ifndef PLAYER_H
#define PLAYER_H

class Ai : public Player {
public:
	Ai(std::string n, bool a);
	bool next_turn();
};

#endif // !PLAYER_H


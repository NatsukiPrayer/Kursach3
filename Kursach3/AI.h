#pragma once
#include "Player.h"
#ifndef PLAYER_H
#define PLAYER_H

class AI : public Player {
public:
	bool next_turn();
};

#endif // !PLAYER_H


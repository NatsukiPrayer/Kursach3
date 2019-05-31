#include "pch.h"
#include "AI.h"

bool AI::next_turn()
{
	Player::next_turn();
	return Human;
}

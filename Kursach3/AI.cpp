#include "pch.h"
#include "AI.h"

Ai::Ai(std::string n, bool a)
	:Player(n, a)
{
}

bool Ai::next_turn()
{
	return false;
}

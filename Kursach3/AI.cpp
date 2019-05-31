#include "pch.h"
#include "AI.h"

std::string Ai::get_name()
{
	Player::get_name();
	return nick;
}

Ai::Ai(std::string n, bool a)
	:Player(n, a)
{
}

bool Ai::next_turn()
{
	return false;
}

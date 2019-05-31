#include "pch.h"
#include "Player.h"

std::string Player::get_name()
{
	return nick;
}

Player::Player(std::string n, bool a)
	:nick(n), alive(a)
{
}

bool Player::next_turn()
{
	return alive;
}

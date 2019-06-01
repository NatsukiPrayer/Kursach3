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

void Player::turn(Deck &d1, Deck &d2, int p)
{
	d1.get_card(d2, p);
	d2.card_out(p);
}

bool Player::next_turn()
{
	return alive;
}

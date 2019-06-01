#include "pch.h"
#include "Human.h"

std::string Human::get_name()
{
	Player::get_name();
	return nick;
}

Human::Human(std::string n, bool a)
	:Player(n, a)
{
}

bool Human::next_turn()
{
	return true;
}

void Human::turn(Deck &d1, Deck &d2, int p)
{
Player::turn(d1, d2, p);
}

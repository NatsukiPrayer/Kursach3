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

/*void Human::global_turn_start(Ai& ai1, Ai& ai2, Ai& ai3)
{
	this->attacking = true;
	ai1.set_state(1, true);
	ai2.set_state(2, true);
	ai3.set_state(2, true);
}*/

void Human::set_state(int i, bool s)
{
	Player::set_state(i, s);
}

bool Human::next_turn()
{
	return true;
}

bool Human::Padd_con(Deck d1, Deck d2)
{
	return Player::Padd_con(d1, d2);
}

void Human::turn(Deck &d1, Deck &d2, int p)
{
Player::turn(d1, d2, p);
}

void Human::Pturn_con(Deck h, int &cc) {
	Player::Pturn_con(h, cc);
}

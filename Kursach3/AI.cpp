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

void Ai::set_state(int i, bool s)
{
	Player::set_state(i, s);
}

/*void Ai::global_turn_start(Human& mc, Ai& ai1, Ai& ai2)
{
	this->attacking = true;
	mc.set_state(1, true);
	ai1.set_state(2, true);
	ai2.set_state(2, true);
}*/

void Ai::beat(Deck &d1, Deck &d2, Deck &d3, int b) //d1 - table_beat, d2 - hand, d3 - table
{
	int t = std::rand() % d2.get_size_of_deck();
	Player::beat(d1, d2, d3, t, b);
}

bool Ai::next_turn()
{
	return false;
}

bool Ai::Pturn_con(Deck h)
{
	while (1) {
		if (h.get_size_of_deck() == 0) {
			return false;
		}
		else {
			return true;
		}
	}
}

bool Ai::Padd_con(Deck d1, Deck d2)
{
	return Player::Padd_con(d1, d2);
}

void Ai::turn(Deck & d1, Deck & d2)
{
	int p = std::rand() % d2.get_size_of_deck();
	Player::turn(d1, d2, p);
}


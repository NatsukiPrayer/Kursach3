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

void Ai::turn(Deck & d1, Deck & d2)
{
	int p = std::rand() % d2.get_size_of_deck();
	Player::turn(d1, d2, p);
}

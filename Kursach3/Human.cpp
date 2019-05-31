#include "pch.h"
#include "Human.h"

Human::Human(std::string n, bool a)
	:Player(n, a)
{
}

bool Human::next_turn()
{
	return true;
}

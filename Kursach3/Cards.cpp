#include "pch.h"
#include "Cards.h"

Cards::Cards()
{}

Cards::Cards(int r, int s, bool t)
	:trump(t)
{
	if (r >= 9)
		rang = 9;
	else if (r <= 0)
		rang = 0;
	else
		rang = r;

	if (s >= 3)
		suit = 3;
	else if (s <= 0)
		suit = 0;
	else
		suit = s;
}

void Cards::beat(Cards c1)
{}

void Cards::info()
{
	if (rang == 0)
		std::cout << " six of ";
	else if (rang == 1)
		std::cout << " seven of ";
	else if (rang == 2)
		std::cout << " eight of ";
	else if (rang == 3)
		std::cout << " nine of ";
	else if (rang == 4)
		std::cout << " ten of ";
	else if (rang == 5)
		std::cout << " jack of ";
	else if (rang == 6)
		std::cout << " queen of ";
	else if (rang == 7)
		std::cout << " king of ";
	else if (rang == 8)
		std::cout << " ace of ";
	if (suit == 0)
		std::cout << "hearts " << std::endl;
	else if (suit == 1)
		std::cout << "spade " << std::endl;
	else if (suit == 2)
		std::cout << "diamonds " << std::endl;
	else if (suit == 3)
		std::cout << "clubs " << std::endl;

}

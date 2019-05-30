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

#include "pch.h"
#include "Cards.h"

Cards::Cards(int r, int s, bool t)
	:rang(r), trump(t)
{
	if (s >= 3)
		suit = 3;
	else if (s <= 0)
		suit = 0;
	else
		suit = s;
}

void Cards::beat(Cards c1)
{}

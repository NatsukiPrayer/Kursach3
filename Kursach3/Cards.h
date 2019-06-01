#pragma once
#include <iostream>
class Cards {
protected:
	int rang;
	int suit;
	bool trump;
public:
	friend class Deck;
	Cards();
	Cards(int r, int s, bool t);
	void beat(Cards c1);
	void info();

};

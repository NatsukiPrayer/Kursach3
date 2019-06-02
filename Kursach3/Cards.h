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
	int get_rang();
	int get_suit();
	bool get_trump();
	void beat(Cards c1);
	void info();

};

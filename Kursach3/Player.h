#pragma once
#include "Deck.h"
#include <string>
class Player {
protected:
	std::string nick;
	bool alive;
public:
	std::string get_name();
	Player(std::string n, bool a);
	void Pturn_con(Deck, int&);
	void add(Deck&, Deck&, int);
	void turn(Deck&, Deck&, int);
	void beat(Deck&, Deck&, Deck&, int, int);
	virtual bool next_turn();
};

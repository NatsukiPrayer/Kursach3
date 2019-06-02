#pragma once
#include "Deck.h"
#include <string>
class Player {
protected:
	std::string nick;
	bool alive;
	bool attacking;
	bool defendeing;
	bool co_attacking;
public:
	std::string get_name();
	Player(std::string n, bool a);
	bool Padd_con(Deck, Deck);
	void Pturn_con(Deck, int&);
	void add(Deck&, Deck&, int);
	void turn(Deck&, Deck&, int);
	void beat(Deck&, Deck&, Deck&, int, int);
	virtual bool next_turn();
};

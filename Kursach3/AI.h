#pragma once
#include "Player.h"
#include "Human.h"
#ifndef PLAYER_H
#define PLAYER_H

class Ai : public Player {
public:
	std::string get_name();
	Ai(std::string n, bool a);
	void set_state(int i, bool s);
	//void global_turn_start(Human&, Ai&, Ai&);
	void beat(Deck&, Deck&, Deck&, int); //d1 - table_beat, d2 - hand, d3 - table
	bool next_turn();
	bool Pturn_con(Deck);
	bool Padd_con(Deck, Deck);
	void turn(Deck&, Deck&);
};

#endif // !PLAYER_H


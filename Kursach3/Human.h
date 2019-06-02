#pragma once
#include "Player.h"
#include "AI.h"
#ifndef HUMAN_H
#define HUMAN_H


class Human : public Player {
public:
	std::string get_name();
	Human(std::string n, bool a);
	//void global_turn_start(Ai&, Ai&, Ai&);
	void set_state(int i, bool s);
	bool next_turn();
	bool Padd_con(Deck, Deck);
	void Pturn_con(Deck, int&);
	void turn(Deck&, Deck&, int);
};

#endif // !HUMAN_H

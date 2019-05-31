#pragma once
#include "Player.h"
#ifndef HUMAN_H
#define HUMAN_H

class Human : public Player {
public:
	Human(std::string n, bool a);
	bool next_turn();
};

#endif // !HUMAN_H

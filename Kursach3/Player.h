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
	bool add_card(Deck d1, Cards c1);
	Player(std::string n, bool a);
	void set_state(int, bool);
	void info(Deck, Deck, Deck, Deck);
	virtual void global_turn();
	bool Pbeat_con(Deck, Deck, int);
	void take(Deck&, Deck&, Deck&);
	bool Padd_con(Deck, Deck);
	void Pturn_con(Deck, int&);
	void add(Deck&, Deck&, int);
	void turn(Deck&, Deck&, int);
	void beat(Deck&, Deck&, Deck&, int, int);
	virtual bool next_turn();
};

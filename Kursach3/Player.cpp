#include "pch.h"
#include "Player.h"

std::string Player::get_name()
{
	return nick;
}

Player::Player(std::string n, bool a)
	:nick(n), alive(a)
{
}

void Player::turn(Deck &d1, Deck &d2, int p)
{
	d1.get_card(d2, p);
	d2.card_out(p);
}

void Player::beat(Deck & d1, Deck & d2, Deck & d3, int t, int b)
{
	if (d2.get_card_out(t).get_trump() == true && d3.get_card_out(b).get_trump() == false) {
		d1.get_card(d2, t);
		d2.card_out(t);
	}
	else if (d2.get_card_out(t).get_trump() == true && d3.get_card_out(b).get_trump() == true) {
		if (d2.get_card_out(t).get_rang() > d3.get_card_out(b).get_rang()) {
			d1.get_card(d2, t);
			d2.card_out(t);
		}
		else
			std::cout << "This card rang it too low" << std::endl;
	}
	else if (d2.get_card_out(t).get_trump() == false && d3.get_card_out(b).get_trump() == true)
		std::cout << "You can't beat trump with normal card" << std::endl;
	else if (d2.get_card_out(t).get_trump() == false && d3.get_card_out(b).get_trump() == false) {
		if (d2.get_card_out(t).get_suit() == d3.get_card_out(b).get_suit()) {
			if (d2.get_card_out(t).get_rang() > d3.get_card_out(b).get_rang()) {
				d1.get_card(d2, t);
				d2.card_out(t);
			}
			else
				std::cout << "This card rang it too low" << std::endl;
		}
		else if (d2.get_card_out(t).get_suit() != d3.get_card_out(b).get_suit())
			std::cout << "You can't beat card with different suit" << std::endl;
	}
	
}

bool Player::next_turn()
{
	return alive;
}

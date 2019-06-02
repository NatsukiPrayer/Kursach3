#include "pch.h"
#include "Player.h"


bool add_card(Deck d1, Cards c1) {
	bool con = false;
	int j=0;
	while (j < d1.get_size_of_deck()) {
		if (con == false) {
			if (c1.get_rang() != d1.get_rng_coll(j))
				j++;
			else {
				con = true;
				break;
			}

		}
		else
			break;
	}
	return con;
}



std::string Player::get_name()
{
	return nick;
}

Player::Player(std::string n, bool a)
	:nick(n), alive(a)
{
}

void Player::Pturn_con(Deck h, int &cc)
{
	std::cout << "Now is your turn, choose a card to play: ";
	while (1) {
		std::cin >> cc;
		if (h.get_size_of_deck() == 0)
			std::cout << "Your hand is out" << std::endl;
		else if (cc > h.get_size_of_deck() || cc < 0)
			std::cout << "You don't own a card under this number" << std::endl;
		else
			break;
	}
}

void Player::add(Deck & d1, Deck & d2, int p)
{
	if (add_card(d1, d2.get_card_out(p)) == true) {
		d1.get_card(d2, p);
		d2.card_out(p);
	}
	else
		std::cout << "There is no such card on the table, so you can't add this one to the rest ";
}

void Player::turn(Deck &d1, Deck &d2, int p)
{
	d1.get_card(d2, p);
	d1.set_add_rng_coll(d2.get_card_out(p).get_rang());
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



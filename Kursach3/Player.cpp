#include "pch.h"
#include "Player.h"


bool Player::add_card(Deck d1, Cards c1) {
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

void Player::set_state(int i, bool s)
{
	if (i == 0)
		attacking = s;
	else if (i == 1)
		defendeing = s;
	else
		co_attacking = s;
}

void Player::info(Deck d1, Deck d2, Deck d3, Deck d4) {
	system("cls");
	switch (d4.get_trump()) {
	case 0:
		std::cout << "Trump is heart " << std::endl;
		break;
	case 1:
		std::cout << "Trump is spade " << std::endl;
		break;
	case 2:
		std::cout << "Trump is diamond " << std::endl;
		break;
	case 3:
		std::cout << "Trump is club " << std::endl;
		break;
	}
	std::cout << "Your hand:" << std::endl;
	d2.deck_info();
	std::cout << "Table: " << std::endl;
	d1.deck_info();
	std::cout << "Beat table:" << std::endl;
	d3.deck_info();
}

void Player::global_turn()
{
}

bool Player::Pbeat_con(Deck d1, Deck d2, int b)
{
	for (int i = 0; i < d2.get_size_of_deck(); i++) {
		if (d2.get_card_out(i).get_trump() == true) {
			if (d2.get_card_out(i).get_suit() == d1.get_card_out(b).get_suit()) {
				if (d2.get_card_out(i).get_rang() > d1.get_card_out(b).get_rang())
					return true;
			}
			else 
				return true;
		}
		else {
			if (d2.get_card_out(i).get_suit() == d1.get_card_out(b).get_suit()) {
				if (d2.get_card_out(i).get_rang() > d1.get_card_out(b).get_rang())
					return true;
			}
		}

	}
	return false;
}

void Player::take(Deck &d1, Deck &d2, Deck &d3)
{
	for (int u = 0; u < d1.get_size_of_deck(); u++) {
		d2.get_card(d1, u);
		d1.card_out(u);
	}
	for (int u = 0; u < d3.get_size_of_deck(); u++) {
		d2.get_card(d3, u);
		d3.card_out(u);
	}
}

bool Player::Padd_con(Deck d1, Deck d2)
{
	for (int h = 0; h < d1.get_size_of_deck(); h++) {
		for (int i = 0; i < d2.get_size_of_deck(); i++) {
			if (d1.get_rng_coll(h) == d2.get_rng_coll(i))
				return true;
		}
	}
	return false;
}

void Player::Pturn_con(Deck h, int &cc)
{
	std::cout << "Now is your turn, choose a card to play: ";
	while (1) {
		std::cin >> cc;
		if (h.get_size_of_deck() == 0) {
			std::cout << "Your hand is out" << std::endl;
			break;
		}
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
	d2.card_out(p);
}

bool Player::beat(Deck & d1, Deck & d2, Deck & d3, int t, int b) //d1 - table_beat, d2 - hand, d3 - table
{
	if (d2.get_card_out(t).get_trump() == true && d3.get_card_out(b).get_trump() == false) {
		d1.get_card(d2, t);
		d2.card_out(t);
		return true;
	}
	else if (d2.get_card_out(t).get_trump() == true && d3.get_card_out(b).get_trump() == true) {
		if (d2.get_card_out(t).get_rang() > d3.get_card_out(b).get_rang()) {
			d1.get_card(d2, t);
			d2.card_out(t);
			return true;
		}
		else {
			std::cout << "This card rang it too low" << std::endl;
			return false;
		}
	}
	else if (d2.get_card_out(t).get_trump() == false && d3.get_card_out(b).get_trump() == true) {
		std::cout << "You can't beat trump with normal card" << std::endl;
		return false;
	}
	else if (d2.get_card_out(t).get_trump() == false && d3.get_card_out(b).get_trump() == false) {
		if (d2.get_card_out(t).get_suit() == d3.get_card_out(b).get_suit()) {
			if (d2.get_card_out(t).get_rang() > d3.get_card_out(b).get_rang()) {
				d1.get_card(d2, t);
				d2.card_out(t);
				return true;
			}
			else {
				std::cout << "This card rang it too low" << std::endl;
				return false;
			}
		}
		else if (d2.get_card_out(t).get_suit() != d3.get_card_out(b).get_suit()) {
			std::cout << "You can't beat card with different suit" << std::endl;
			return false;
		}
	}
	
}

bool Player::next_turn()
{
	return alive;
}



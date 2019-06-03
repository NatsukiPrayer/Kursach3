// Kursach3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include "Cards.h"
#include "Deck.h"
#include "Player.h"
#include "Human.h"
#include "AI.h"
using namespace std;

int main()
{
	string name;
	string answer;
	string Pl[6];
	int ai_num;
	vector <Ai> bots;
	cout << "Before we start, introduce yourself: ";
	cin >> name;
	Human MC(name, true);
	cout << "So, let's our short story begin " << endl
		<< "This bar isn't" << endl
		<< "a good place to be in, but this evening you felt like someone who needed a place like" << endl
		<< "this. You've chosen one of the nearest table with few omnics sitting at it. How many of" << endl
		<< "them are there?" << endl;
	cin >> ai_num;
	while (1) {
		if (ai_num > 5) {
			cout << "You shook your head to get a fresh look at the table. Only thoughts " << endl
				<< "in your mind are all about how could you see more than 3 omnics in such a small bar" << endl
				<< "in junk-town of yours? Of course, it's can't be true." << endl;
			cin >> ai_num;
		}
		else if (ai_num < 1) {
			cout << "You blinked few times before you realized that only few moments earlier there were no one at the table, " << endl
				<< "but now, you could swear, there are some omnics, your own eyes can't lie you twice!" << endl;
			cin >> ai_num;
		}
		else
			break;
	}
	cout << "After you finished your cigarette you thrown butt at floor and stepped on it. No one even" << endl
		<< "tried to look at you, because someone don't even care about things happening out of their" << endl
		<< "own world range, and the others are the same as you. How could you blame your brother? They can't." << endl
		<< "You've taken a seat at the table with the omnics you've seen. They didn't drop a single word, but all" << endl
		<< "three pairs of neon eyes looked at you, and the one who had toxic puprle-colored eyes laid a deck of cards" << endl
		<< "on the top of the table. Few seconds later you've heard deep metal voice which declared only one word." << endl
		<< "-Durak?" << endl
		<< "You've litted up another cigarette and released a small cloud of smoke from your mouth." << endl
		<< "-Durak." << endl;
	for (int i = 0; i < ai_num; i++) {
		bots.push_back(Ai(("Bot" + i), false));
		Pl[i] = bots.at(i).get_name();
	}
	Deck iDeck;
	iDeck.deck_init();
	cout << "After your answered the one who laid the deck took it back  and started to shuffle it." << endl
		<< "Sometimes you think about how smart are they, how adroit. Even their bodies can live more " << endl
		<< "than any human body. Could they be perfect? Could they be a solution humanity's self-destruction?" << endl
		<< "Who knows. You've snuffed out the cigarette with you hand, and it was not only your's stupidity, " << endl
		<< "oh if it could be only stupidity. You just wanted to test a feeling which divides you and these..." << endl
		<< "Creatures. Omnic-croupier finished shuffling and stretched out his hand with the deck to you" << endl;
	iDeck.shuffle();
	while (1) {
		cout << "-Shuffle one more time or we could start?";
		cin >> answer;
		if (answer == "yes" || answer == "Yes" || answer == "Shuffle" || answer == "shuffle" || answer == "one more" || answer == "One more" || answer == "one more time" || answer == "One more time") {
			cout << "-As you want" << endl;
			iDeck.shuffle();
		}
		else if (answer == "no" || answer == "No" || answer == "start" || answer == "Start" || answer == "begin" || answer == "Begin") {
			cout << "-And so we start" << endl;
			iDeck.trump_init();
			iDeck.rng_coll_init();
			break;
		}
		else
			cout << "This is not <yes> and is not <no>. Answer clearer next time " << endl;
	}
	int chosen_card;
	Deck Beated;
	Deck Table;
	Deck Table_beat;
	vector <Deck> Hand;
	for (int i = 0; i < ai_num + 1; i++) {
		Hand.push_back(Deck());
		for (int k = 0; k < 6; k++) {
			Hand.at(i).get_card(iDeck, 0);
			iDeck.card_out(0);
		}
	}
	system("cls");
	bool turn = true;
	while (1) {
		while (1) {
			int card_count = -1;
			int player_turn = 0;
			for (int g = 0; g < ai_num; g++) {
				MC.info(Table, Hand.at(0), Table_beat, iDeck);
				if (iDeck.get_size_of_deck() > 0) {
					if (g == 0) {
						if (Hand.at(0).get_size_of_deck() != 0) {
							MC.Pturn_con(Hand.at(0), chosen_card);
							MC.turn(Table, Hand.at(0), chosen_card);
							MC.info(Table, Hand.at(0), Table_beat, iDeck);
							card_count += 1;
						}
					}
				}
				for (int n = 0; n < ai_num; n++) {
					while (card_count < 6) {
						if (n == (g + 1) % 6)
							break;
						else {
							if (n == 0) {
								if (MC.Padd_con(Table, Hand.at(0)) == true || MC.Padd_con(Table_beat, Hand.at(0)) == true) {
									cout << "Now you can add cards if you want to: ";
									while (MC.Padd_con(Table, Hand.at(0)) == true) {
										cin >> chosen_card;
										MC.add(Table, Hand.at(0), chosen_card);
										MC.info(Table, Hand.at(0), Table_beat, iDeck);
										card_count += 1;
									}
								}

							}
							else {
								if (bots.at(n).Padd_con(Table, Hand.at(0)) == true || MC.Padd_con(Table_beat, Hand.at(0)) == true) {
									cout << "Omnics adding cards" << endl;
									while (bots.at(n).Padd_con(Table, Hand.at(0)) == true) {
										MC.add(Table, Hand.at(0), chosen_card);
										MC.info(Table, Hand.at(0), Table_beat, iDeck);
										card_count += 1;
									}
								}
							}
							Hand.at(1).deck_info();
							for (int h = -1; h < card_count; h++) {
								if (bots.at((g + 1) % 6).Pturn_con(Hand.at((g + 1) % 6)) == true) {
									if (bots.at((g + 1) % 6).Pbeat_con(Table, Hand.at((g + 1) % 6), h + 1) == true || MC.Padd_con(Table_beat, Hand.at(player_turn)) == true) {
										int choice = std::rand() % 2;
										if (choice == 0) {
											bots.at((g + 1) % 6).take(Table, Hand.at((g + 1) % 6), Table_beat);
											MC.info(Table, Hand.at(0), Table_beat, iDeck);
											break;
										}
										if (choice > 0) {
											while ((bots.at((g + 1) % 6).Pturn_con(Hand.at((g + 1) % 6)) == true))
												bots.at((g + 1) % 6).beat(Table_beat, Hand.at((g + 1) % 6), Table, h + 1);
											MC.info(Table, Hand.at(0), Table_beat, iDeck);
										}
										//MC.info(Table, Hand.at(0), Table_beat, iDeck);
										//break;
									}
								}

							}
						}
						system("pause");
					}
				}
			}
		}
	}
}
			

/*
if (MC.Padd_con(Table, Hand.at(player_turn)) == true || MC.Padd_con(Table_beat, Hand.at(player_turn)) == true) {
										cout << endl;
										for (int h = -1; h < card_count; h++) {
											if (bots.at(player_turn + 1).Pturn_con(Hand.at(player_turn + 1)) == true) {
												if (bots.at(player_turn + 1).Pbeat_con(Table, Hand.at(player_turn + 1), h + 1) == true || MC.Padd_con(Table_beat, Hand.at(player_turn)) == true) {
													int choice = std::rand() % 2;
													if (choice == 0) {
														bots.at(player_turn + 1).take(Table, Hand.at(player_turn + 1), Table_beat);
														MC.info(Table, Hand.at(player_turn), Table_beat, iDeck);
														break;
													}
													if (choice > 0) {
														while ((bots.at(player_turn + 1).Pturn_con(Hand.at(player_turn + 1)) == true))
															bots.at(player_turn + 1).beat(Table_beat, Hand.at(player_turn + 1), Table, h + 1);
														MC.info(Table, Hand.at(0), Table_beat, iDeck);
													}
												}
												else {
													bots.at(player_turn + 1).take(Table, Hand.at(player_turn + 1), Table_beat);
													MC.info(Table, Hand.at(0), Table_beat, iDeck);
												}
											}
										}
									}
*/
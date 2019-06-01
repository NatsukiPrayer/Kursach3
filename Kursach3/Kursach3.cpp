// Kursach3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Cards.h"
#include "Deck.h"
#include "Player.h"
#include <vector>
#include "AI.h"
using namespace std;

int main()
{
	string name;
	string answer;
	string Pl[4];
	vector <Ai> bots;
	int ai_num;
	cout << "Before we start, introduce yourself: ";
	cin >> name;
	cout << "So, let's our short story begin " << endl
	    << "This bar isn't" << endl
		<< "a good place to be in, but this evening you felt like someone who needed a place like" << endl
		<< "this. You've chosen one of the nearest table with few omnics sitting at it. How many of" << endl
		<< "them are there?" << endl;
	cin >> ai_num;
	while (1) {
		if (ai_num > 3) {
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
		bots.push_back(Ai("Bot", false));
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
			if (answer == "yes") {
				cout << "As you want" << endl;
				iDeck.shuffle();
			}
			else if (answer == "no") {
				cout << "And so we begin" << endl;
				break;
			}
			else 
				cout << "This is not <yes> and is not <no>. Answer clearer next time " << endl;
		}
		iDeck.trump_init();
		while (1) {
			int turn_count = 0;
			Deck Beated;
			vector <Deck> Hand;
			for (int i = 0; i < ai_num; i++) {
				Hand.push_back(Deck());
				//Hand.at(i).get_card()
			}



			
		}
}


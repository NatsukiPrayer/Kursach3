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
	vector <Ai> bots;
	int ai_num;
	cout << "Enter number of AI players(one, two or three): ";
	cin >> ai_num;
	while (1) {
		if (ai_num > 3) {
			cout << "Wrong number of players exception, enter correct number: ";
			cin >> ai_num;
		}
		else if (ai_num < 1) {
			cout << "Wrong number of players exception, enter correct number: ";
			cin >> ai_num;
		}
		else
			break;
	}
	for (int i=0; i < ai_num; i++) {
		bots.push_back(Ai("Bot " << i + 1, false));
	}
	Deck iDeck;
	iDeck.deck_init();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "           =============================================================                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "          |                                                             |                " << endl;
	cout << "           =============================================================                " << endl;
}


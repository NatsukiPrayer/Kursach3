#pragma once
#include <vector>
class Cards {
private:
	int rang;
	int suit;
	bool trump;
public:
	Cards(int r, int s, bool t);
	void beat(Cards c1);
};

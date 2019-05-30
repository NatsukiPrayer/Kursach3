#pragma once
class Cards {
protected:
	int rang;
	int suit;
	bool trump;
public:
	Cards();
	Cards(int r, int s, bool t);
	void beat(Cards c1);
};

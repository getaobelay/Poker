#pragma once

class Card {
public:

	enum Suits {
		HEARTS = 3,
		DIAMONDS,
		CLUBS,
		SPADES
	};

	enum Ranks {
		ACE = 1,
		TOW,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING
	};


	Card(Ranks Rank, Suits Suit);
	virtual ~Card();

	int GetRank();
	int GetSuit();

	virtual int GetFaceValue();

	void Print();
private:
	int Rank;
	int Suit;
};
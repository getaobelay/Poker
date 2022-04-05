#pragma once
#include "Card.h"
#include <deque>
class Player {
public:

	enum HandStatus {
		HigherCard = 1,
		Pair,
		TowPair,
		ThreeOfKind,
		FourOfKind,
		Straight,
		FullHouse,
	};



	bool IsWinner = false;
	void SetHand(std::deque<Card*> hand);
	std::deque<Card*> GetHand();
	void PrintHand();
	void SetHandStatus(HandStatus status);
	HandStatus GetHandStatus();
private:
	std::deque<Card*> Hand;
	HandStatus handStatus;

};


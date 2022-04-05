#pragma once
#include "Card.h"
#include <deque>
class Player {
public:
	void SetHand(std::deque<Card*> hand);
	std::deque<Card*> GetHand();
	void PrintHand();
private:
	std::deque<Card*> Hand;

};


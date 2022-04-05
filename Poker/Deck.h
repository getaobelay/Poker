#pragma once
#include <vector>
#include "Card.h"
#include <deque>

class Deck {
public:
	Deck();
	~Deck();

	void Print();
	void Shuffle();
	std::deque<Card*> DealCards();
	Card* TopCard();
	void PopCard();
private:
	int max_num_card = 2;
	void Initialize();
	void Sort(std::deque<Card*>& hand);
	std::deque<Card*> deck;
};
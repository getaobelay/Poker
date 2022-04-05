#include "Deck.h"
#include <iostream>
#include <algorithm>

Deck::Deck()
{
	Initialize();

}

Deck::~Deck()
{
	for (Card* card : deck) {
		delete card;
	}

	deck.clear();
}

void Deck::Print()
{
	for (Card* card : deck) {
		card->Print();
		std::cout << std::endl;
	}
}

void Deck::Shuffle()
{
	std::random_shuffle(deck.begin(), deck.end());
}

std::deque<Card*> Deck::DealCards()
{
	std::deque<Card*> hand;

	for (int i = 0; i < max_num_card;i++) {
		Card* card = deck.front();
		hand.push_front(card);
		deck.erase(deck.begin());
	}

	Sort(hand);

	return hand;
}

void Deck::Sort(std::deque<Card*>& hand) {
	for (size_t i = 0; i < max_num_card; i++) {
		for (size_t j = i + 1; j < max_num_card; j++)
		{
			if (hand[i]->GetFaceValue() > hand[j]->GetFaceValue()) {
				Card* temp = hand[i];
				hand[i] = hand[j];
				hand[j] = temp;
			}
		}
	}
}

Card* Deck::TopCard()
{
	return deck.front();
}



void Deck::PopCard()
{
	deck.erase(deck.begin());
}

void Deck::Initialize()
{
	for (int col = (int)Card::Ranks::ACE; col <= (int)Card::Ranks::KING; col++)
	{
		for (int row = (int)Card::Suits::HEARTS; row <= (int)Card::Suits::SPADES; row++)
		{
			deck.push_front(new Card((Card::Ranks)col, (Card::Suits)row));
		}
	}
}

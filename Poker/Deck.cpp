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


/// <summary>
/// Prints this instance.
/// </summary>
void Deck::Print()
{
	for (Card* card : deck) {
		card->Print();
		std::cout << std::endl;
	}
}


/// <summary>
/// Shuffles this instance.
/// </summary>
void Deck::Shuffle()
{
	std::random_shuffle(deck.begin(), deck.end());
}


/// <summary>
/// Deals the cards.
/// </summary>
/// <returns></returns>
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


/// <summary>
/// Sorts the specified hand.
/// </summary>
/// <param name="hand">The hand.</param>
void Deck::Sort(std::deque<Card*>& hand) {
	for (size_t i = 0; i < max_num_card; i++) {
		for (size_t j = i + 1; j < max_num_card; j++)
		{
			if (hand[i]->GetRank() > hand[j]->GetRank()) {
				Card* temp = hand[i];
				hand[i] = hand[j];
				hand[j] = temp;
			}
		}
	}
}


/// <summary>
/// Return the top the card.
/// </summary>
/// <returns></returns>
Card* Deck::TopCard()
{
	return deck.front();
}


/// <summary>
/// Pops the card.
/// </summary>
void Deck::PopCard()
{
	deck.erase(deck.begin());
}


/// <summary>
/// Initializes this instance.
/// </summary>
void Deck::Initialize()
{
	for (int col = (int)Card::Ranks::TOW; col <= (int)Card::Ranks::ACE; col++)
	{
		for (int row = (int)Card::Suits::HEARTS; row <= (int)Card::Suits::SPADES; row++)
		{
			deck.push_front(new Card((Card::Ranks)col, (Card::Suits)row));
		}
	}
}

#include "Card.h"
#include <iostream>

Card::Card(Ranks Rank, Suits Suit) : Rank(Rank), Suit(Suit)
{
}

Card::~Card()
{
}

int Card::GetRank()
{
	return Rank;
}

int Card::GetSuit()
{
	return Suit;
}

int Card::GetFaceValue()
{
	return static_cast<int>(Rank);

}

void Card::Print()
{


	if (Rank == ACE) {
		std::cout << "Ace" << " ";
	}

	else if (Rank == JACK) {
		std::cout << "Jack" << " ";
	}


	else if (Rank == QUEEN) {
		std::cout << "Queen" << " ";
	}

	else if (Rank == KING) {
		std::cout << "King" << " ";
	}

	else if (Rank <= TEN) {
		std::cout << Rank << " ";
	}

	if (Suit == DIAMONDS) {
		std::cout << "Of" << " " << "Diamonds" << " ";

	}

	else if (Suit == CLUBS) {
		std::cout << "Of" << " " << "Clubs" << " ";
	}

	else if (Suit == HEARTS) {
		std::cout << "Of" << " " << "Hearts" << " ";
	}

	else if (Suit == SPADES) {
		std::cout << "Of" << " " << "Spades" << " ";
	}

	std::cout << std::endl;


}

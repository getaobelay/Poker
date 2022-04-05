#include "Player.h"
#include <iostream>

void Player::SetHand(std::deque<Card*> hand)
{
	Hand = hand;
}

void Player::PrintHand() {

	for (size_t i = 0; i < Hand.size(); i++)
	{
		Hand[i]->Print();


		switch (handStatus)
		{
		case Player::Pair:
			std::cout << "Pair" << std::endl;
			break;
		case Player::TowPair:
			std::cout << "Tow Pair" << std::endl;
			break;
		case Player::ThreeOfKind:
			std::cout << "Three Of Kind" << std::endl;
			break;
		case Player::FourOfKind:
			std::cout << "Four Of Kind" << std::endl;
			break;
		case Player::Straight:
			std::cout << "Straight" << std::endl;
			break;
		case Player::FullHouse:
			std::cout << "FullHouse" << std::endl;
			break;
		default:
			break;
		}

	}
}

void Player::SetHandStatus(HandStatus status)
{
	handStatus = status;
}

Player::HandStatus Player::GetHandStatus()
{
	return handStatus;
}

std::deque<Card*> Player::GetHand()
{
	return Hand;
}

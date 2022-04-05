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
	}
}

std::deque<Card*> Player::GetHand()
{
	return Hand;
}

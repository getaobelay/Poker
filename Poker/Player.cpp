#include "Player.h"
#include <iostream>



/// <summary>
/// Sets the hand.
/// </summary>
/// <param name="hand">The hand.</param>
void Player::SetHand(std::deque<Card*> hand)
{
	Hand = hand;
}



/// <summary>
/// Prints the hand.
/// </summary>
void Player::PrintHand() {

	for (size_t i = 0; i < Hand.size(); i++)
	{
		Hand[i]->Print();
	}

	std::cout << std::endl;

}



/// <summary>
/// Prints the hand status.
/// </summary>
void Player::PrintHandStatus() {
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




/// <summary>
/// Sets the hand status.
/// </summary>
/// <param name="status">The status.</param>
void Player::SetHandStatus(HandStatus status)
{
	handStatus = status;
}


/// <summary>
/// Gets the hand status.
/// </summary>
/// <returns></returns>
Player::HandStatus Player::GetHandStatus()
{
	return handStatus;
}


/// <summary>
/// Gets the hand.
/// </summary>
/// <returns></returns>
std::deque<Card*> Player::GetHand()
{
	return Hand;
}

#include "Game.h"
#include <iostream>

Game::Game()
{
	Initialize();
}


/// <summary>
/// Gets the players.
/// </summary>
/// <returns></returns>
std::vector<Player> Game::GetPlayers()
{
	return players;
}

/// <summary>
/// Initializes this instance.
/// </summary>
void Game::Initialize()
{
	deck.Shuffle();
	SetPlayers();
	PreFlop();
	Flop();
	SetPlayerHandStatus();
}


/// <summary>
/// Prints the cards.
/// </summary>
void Game::PrintCards() {
	for (size_t i = 0; i < cards.size(); i++)
	{
		cards[i]->Print();
	}

	std::cout << std::endl << std::endl;


}
void Game::SetPlayers()
{
	for (int player = 0; player < number_of_players; player++) {

		Player new_player;
		players.push_back(new_player);
	}
}

std::vector<Card*> Game::GetCards()
{
	return cards;
}
/// <summary>
/// Pres the flop.
/// </summary>
void Game::PreFlop() {

	for (int player = 0; player < number_of_players; player++) {

		players[player].SetHand(deck.DealCards());
	}
}
/// <summary>
/// Flops this instance.
/// </summary>
void Game::Flop()
{
	for (size_t i = 0; i < 5; i++) {
		Card* card = deck.TopCard();
		deck.PopCard();

		cards.push_back(card);
		Sort();
	}
}



/// <summary>
/// Sorts this instance.
/// </summary>
void Game::Sort() {
	for (size_t i = 0; i < cards.size(); i++) {
		for (size_t j = i + 1; j < cards.size(); j++)
		{
			if (cards[i]->GetRank() > cards[j]->GetRank()) {
				Card* temp = cards[i];
				cards[i] = cards[j];
				cards[j] = temp;
			}
		}
	}
}

/// <summary>
/// Set the player hand status.
/// </summary>
/// <returns></returns>

void Game::SetPlayerHandStatus() {
	for (size_t i = 0; i < players.size(); i++)
	{
		if (IsPair(players[i].GetHand())) {

			players[i].SetHandStatus(Player::HandStatus::Pair);
		}

		if (IsTwoPair(players[i].GetHand())) {
			players[i].SetHandStatus(Player::HandStatus::TowPair);

		}

		if (IsThreeKind(players[i].GetHand())) {
			players[i].SetHandStatus(Player::HandStatus::ThreeOfKind);

		}

		if (IsFourKind(players[i].GetHand())) {
			players[i].SetHandStatus(Player::HandStatus::FourOfKind);

		}


		if (IsStraight(players[i].GetHand())) {
			players[i].SetHandStatus(Player::HandStatus::Straight);

		}

		if (IsFullHouse(players[i].GetHand())) {
			players[i].SetHandStatus(Player::HandStatus::FullHouse);

		}


	}

}


/// <summary>
/// Determines whether the specified hand is pair.
/// </summary>
/// <param name="hand">The hand.</param>
/// <returns>
///   <c>true</c> if the specified hand is pair; otherwise, <c>false</c>.
/// </returns>
bool Game::IsPair(const std::deque<Card*>& hand) {
	for (size_t i = 0; i < cards.size(); i++)
	{
		for (size_t j = 0; j < hand.size(); j++)
		{
			if (cards[i]->GetRank() == hand[j]->GetRank()) {
				return true;
			}
		}
	}
	return false;
}


/// <summary>
/// Determines whether [is two pair] [the specified hand].
/// </summary>
/// <param name="hand">The hand.</param>
/// <returns>
///   <c>true</c> if [is two pair] [the specified hand]; otherwise, <c>false</c>.
/// </returns>
bool Game::IsTwoPair(const std::deque<Card*>& hand) {

	int matchingCards = 0;

	for (size_t i = 0; i < cards.size(); i++)
	{
		for (size_t j = 0; j < hand.size(); j++)
		{
			if (cards[i]->GetRank() == hand[j]->GetRank()) {
				matchingCards++;
			}
		}
	}
	return matchingCards == 2 ? true : false;
}

/// <summary>
/// Determines whether [is three kind] [the specified hand].
/// </summary>
/// <param name="hand">The hand.</param>
/// <returns>
///   <c>true</c> if [is three kind] [the specified hand]; otherwise, <c>false</c>.
/// </returns>
bool Game::IsThreeKind(const std::deque<Card*>& hand) {


	for (size_t i = 0; i < hand.size(); i++)
	{
		int matchingCards = 0;

		for (size_t j = 0; j < cards.size(); j++)
		{
			if (hand[i]->GetRank() == cards[j]->GetRank()) {
				matchingCards++;
			}

			if (matchingCards == 2) {
				return true;
			}
		}
	}


	return false;
}
/// <summary>
/// Determines whether [is four kind] [the specified hand].
/// </summary>
/// <param name="hand">The hand.</param>
/// <returns>
///   <c>true</c> if [is four kind] [the specified hand]; otherwise, <c>false</c>.
/// </returns>
bool Game::IsFourKind(const std::deque<Card*>& hand) {

	for (size_t i = 0; i < cards.size(); i++)
	{
		int matchingCards = 0;

		for (size_t j = 0; j < hand.size(); j++)
		{
			if (cards[i]->GetRank() == hand[j]->GetRank()) {
				matchingCards++;
			}

			if (matchingCards == 3) {
				return true;
			}
		}
	}
	return false;
}


/// <summary>
/// Determines whether the specified hand is straight.
/// </summary>
/// <param name="hand">The hand.</param>
/// <returns>
///   <c>true</c> if the specified hand is straight; otherwise, <c>false</c>.
/// </returns>
bool Game::IsStraight(const std::deque<Card*>& hand) {


	for (size_t i = 0; i < cards.size(); i++)
	{
		int matchingCards = 0;

		for (size_t j = 0; j < hand.size(); j++)
		{
			if (cards[i]->GetRank() != hand[j]->GetRank() + 1) {
				return false;
			}
		}
	}

	return true;
}


/// <summary>
/// Determines whether [is full house] [the specified hand].
/// </summary>
/// <param name="hand">The hand.</param>
/// <returns>
///   <c>true</c> if [is full house] [the specified hand]; otherwise, <c>false</c>.
/// </returns>
bool Game::IsFullHouse(const std::deque<Card*>& hand)
{
	int treeOfKind = 0;


	//Check for a tree of a king

	for (size_t i = 0; i < hand.size(); i++)
	{
		int matchingCards = 0;

		for (size_t j = 0; j < cards.size(); j++)
		{
			if (hand[i]->GetRank() == cards[j]->GetRank()) {
				matchingCards++;
			}

			if (matchingCards == 2) {
				treeOfKind = cards[j]->GetRank();
				break;
			}
		}
	}

	if (treeOfKind == 0) return false;

	//Check for a pair

	for (size_t i = 0; i < cards.size(); i++)
	{
		for (size_t j = 0; j < hand.size(); j++)
		{
			if (cards[i]->GetRank() == hand[j]->GetRank() && cards[i]->GetRank() != treeOfKind) {
				return true;
			}
		}
	}


	return false;
}

bool Game::IsFlush(const std::deque<Card*>& hand)
{
	return false;
}



/// <summary>
/// Gets the winner.
/// </summary>
/// <returns></returns>
Player Game::GetWinner() {

	Player winner;

	for (size_t current = 0; current < players.size(); current++)
	{
		for (size_t next = current + 1; next < players.size(); next++)
		{

			int currentStatus = static_cast<int>(players[current].GetHandStatus());
			int nextStatus = static_cast<int>(players[next].GetHandStatus());


			if (currentStatus > nextStatus) {

				winner = players[current];
			}

			else {
				winner = players[next];
			}



			if (currentStatus == nextStatus) {

				int currentMaxCard = GetMaxCard(current)->GetRank();
				int nextMaxCard = GetMaxCard(next)->GetRank();

				for (size_t i = 0; i < players.size(); i++)
				{
					for (size_t j = i + 1; j < players.size(); j++)
					{
						int tempCurrentMaxCard = GetMaxCard(i)->GetRank();
						int tempNextMaxCard = GetMaxCard(j)->GetRank();

						if (tempCurrentMaxCard > tempNextMaxCard &&
							tempCurrentMaxCard != currentMaxCard &&
							tempNextMaxCard != nextMaxCard) {

							winner = players[current];

						}

						else {
							winner = players[next];
						}
					}
				}

			}

		}
	}

	return winner;
}


/// <summary>
/// Gets the maximum card.
/// </summary>
/// <param name="size">The size.</param>
/// <returns></returns>
Card* Game::GetMaxCard(size_t size)
{
	Card* maxCard = players[size].GetHand()[0];
	std::deque<Card*> cards = players[size].GetHand();

	for (size_t i = 0; i < cards.size(); i++)
	{
		if (maxCard > cards[i]) {
			maxCard = cards[i];
		}
	}

	return maxCard;
}


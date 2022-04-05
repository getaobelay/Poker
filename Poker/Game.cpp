#include "Game.h"
#include <iostream>

Game::Game()
{
	Initialize();
}

std::vector<Player> Game::GetPlayers()
{
	return players;
}


void Game::Initialize()
{
	deck.Shuffle();
	SetPlayers();
	PreFlop();
	Flop();
	SetPlayerHandStatus();
}

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

void Game::PreFlop() {

	for (int player = 0; player < number_of_players; player++) {

		players[player].SetHand(deck.DealCards());
	}
}

void Game::Flop()
{
	for (size_t i = 0; i < 5; i++) {
		Card* card = deck.TopCard();
		deck.PopCard();

		cards.push_back(card);
		Sort();
	}
}

void Game::Sort() {
	for (size_t i = 0; i < cards.size(); i++) {
		for (size_t j = i + 1; j < cards.size(); j++)
		{
			if (cards[i]->GetFaceValue() > cards[j]->GetFaceValue()) {
				Card* temp = cards[i];
				cards[i] = cards[j];
				cards[j] = temp;
			}
		}
	}
}



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
			if (cards[i]->GetFaceValue() == hand[j]->GetFaceValue()) {
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
			if (cards[i]->GetFaceValue() == hand[j]->GetFaceValue()) {
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
			if (hand[i]->GetFaceValue() == cards[j]->GetFaceValue()) {
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
			if (cards[i]->GetFaceValue() == hand[j]->GetFaceValue()) {
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
			if (cards[i]->GetFaceValue() != hand[j]->GetFaceValue() + 1) {
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
			if (hand[i]->GetFaceValue() == cards[j]->GetFaceValue()) {
				matchingCards++;
			}

			if (matchingCards == 2) {
				treeOfKind = cards[j]->GetFaceValue();
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
			if (cards[i]->GetFaceValue() == hand[j]->GetFaceValue() && cards[i]->GetFaceValue() != treeOfKind) {
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


Player Game::GetWinner() {

	Player winner;

	for (size_t current = 0; current < players.size(); current++)
	{
		for (size_t next = current + 1; next < players.size(); next++)
		{
			if (static_cast<int>(players[current].GetHandStatus()) > static_cast<int>(players[next].GetHandStatus())) {

				winner = players[current];
			}

			else {
				winner = players[next];
			}



			if ((int)players[current].GetHandStatus() == (int)players[next].GetHandStatus()) {
				Card* currentMaxCard = GetMaxCard(current);
				Card* nextMaxCard = GetMaxCard(next);

				if (currentMaxCard->GetFaceValue() > nextMaxCard->GetFaceValue()) {

					winner = players[current];

				}

				else {
					winner = players[next];

				}

			}

		}
	}

	return winner;
}

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


#include "Game.h"

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
	DealHands();
	SetCards();
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

void Game::DealHands() {
	for (int player = 0; player < number_of_players; player++) {

		players[player].SetHand(deck.DealCards());
	}
}

void Game::SetCards()
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

bool Game::IsThreeKind(const std::deque<Card*>& hand) {


	for (size_t i = 0; i < cards.size(); i++)
	{
		int matchingCards = 0;

		for (size_t j = 0; j < hand.size(); j++)
		{
			if (cards[i]->GetFaceValue() == hand[j]->GetFaceValue()) {
				matchingCards++;
			}

			if (matchingCards == 2) {
				return true;
			}
		}
	}
	return false;
}

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




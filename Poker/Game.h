#pragma once
#include "Deck.h"
#include "Player.h"
#include<vector>;

class Game {
public:
	Game();
	std::vector<Player> GetPlayers();
	std::vector<Card*> GetCards();

	bool IsPair(const std::deque<Card*>& hand);

	bool IsTwoPair(const std::deque<Card*>& hand);

	bool IsThreeKind(const std::deque<Card*>& hand);

	bool IsFourKind(const std::deque<Card*>& hand);


private:

	Deck deck;
	std::vector<Player> players;
	std::vector<Card*> cards;
	int number_of_players = 3;

	void Initialize();
	void SetPlayers();
	void DealHands();
	void SetCards();
	void Sort();
};


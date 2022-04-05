#pragma once
#include "Deck.h"
#include "Player.h"
#include<vector>;

class Game {
public:

	Game();
	std::vector<Player> GetPlayers();
	std::vector<Card*> GetCards();

	void SetPlayerHandStatus();
	void PrintCards();


	Player GetWinner();



private:

	Deck deck;

	std::vector<Player> players;
	std::vector<Card*> cards;
	int number_of_players = 3;

	void Initialize();
	void SetPlayers();
	void PreFlop();
	void Flop();
	void Turn();
	void Sort();



	bool IsPair(const std::deque<Card*>& hand);
	bool IsTwoPair(const std::deque<Card*>& hand);
	bool IsThreeKind(const std::deque<Card*>& hand);
	bool IsFourKind(const std::deque<Card*>& hand);
	bool IsStraight(const std::deque<Card*>& hand);
	bool IsFullHouse(const std::deque<Card*>& hand);
	bool IsFlush(const std::deque<Card*>& hand);

	Card* GetMaxCard(size_t size);
};


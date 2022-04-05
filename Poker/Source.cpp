#include "Deck.h"
#include <time.h>
#include <iostream>
#include "Player.h"
#include "Game.h"



int main() {

	srand(time(nullptr));

	Game game;

	std::vector<Player> players = game.GetPlayers();

	std::cout << std::endl;
	std::cout << std::endl;

	std::vector<Card*> cards = game.GetCards();
	for (size_t i = 0; i < cards.size(); i++)
	{
		cards[i]->Print();

	}


	std::cout << std::endl << std::endl;




	for (size_t i = 0; i < players.size(); i++)
	{
		players[i].PrintHand();
		std::cout << std::endl;


		if (game.IsPair(players[i].GetHand())) {
			std::cout << "Player " << i << " " << "Pair" << std::endl;
		}

		if (game.IsTwoPair(players[i].GetHand())) {
			std::cout << "Player " << i << " " << "Two Pair" << std::endl;
		}

		if (game.IsThreeKind(players[i].GetHand())) {
			std::cout << "Player " << i << " " << "Three Kind" << std::endl;
		}

		if (game.IsFourKind(players[i].GetHand())) {
			std::cout << "Player " << i << " " << " Four Kind" << std::endl;
		}


		if (game.IsStraight(players[i].GetHand())) {
			std::cout << "Player " << i << " " << " Straight" << std::endl;
		}

		if (game.IsFullHouse(players[i].GetHand())) {
			std::cout << "Player " << i << " " << " FullHouse" << std::endl;
		}

		std::cout << std::endl << std::endl;

	}



	system("pause");
	return 0;
}
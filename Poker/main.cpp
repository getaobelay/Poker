#include "Deck.h"
#include <time.h>
#include <iostream>
#include "Player.h"
#include "Game.h"
#include <string>



int main() {

	srand(time(nullptr));

	Game game;

	game.PrintCards();

	std::vector<Player> players = game.GetPlayers();





	for (size_t i = 0; i < players.size(); i++)
	{
		players[i].PrintHand();

		std::cout << std::endl;


	}

	Player winner = game.GetWinner();


	std::cout << std::endl;
	std::cout << std::endl;

	winner.PrintHand();
	winner.PrintHandStatus();



	system("pause");
	return 0;
}
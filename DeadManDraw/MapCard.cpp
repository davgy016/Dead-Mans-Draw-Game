#include "MapCard.h"
#include <iostream>
#include "Player.h"
#include "Game.h"

MapCard::MapCard(int value) :
	Card(value, Map)
{
}

MapCard::~MapCard()
{
}

std::string MapCard::str() const
{
	return "Map(" + std::to_string(getValue()) + ")";
}

void MapCard::play(Game& game, Player& player)
{
	std::cout << "Draw 3 cards from discard pile. You must play one of the cards drawn into your play area. " << std::endl;

	DiscardPile* discardPile = game.getDiscardPile();

	VectorContainer drawnCards = discardPile->drawCards(3);

	if (drawnCards.empty()) {
		std::cout << "No cards in Discard Pile to draw" << std::endl;
		return;
	}
	//display drawn cards from discard pile
	std::cout << "Drew" << drawnCards.size() << " cards from discard pile: " << std::endl;
	for (int i = 0; i < drawnCards.size(); ++i) {
		std::cout << "  " << i + 1 << "  " << drawnCards[i]->str() << std::endl;
	}

	int choice = 0;
	bool validInput = false;
	while (!validInput) {
		std::cout << "Choose a suit to discard 1-" << drawnCards.size() << std::endl;
		std::cin >> choice;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number." << std::endl;
		}
		else if (choice<1 || choice > drawnCards.size()) {
			std::cout << "Invalid choice. Enter number between 1 and " << drawnCards.size() << std::endl;
		}
		else {
			validInput = true;

		}
	}
	Card* chosenCard = drawnCards[choice - 1];
	player.getPlayArea()->addCard(chosenCard);

	drawnCards.erase(drawnCards.begin() + (choice - 1));

	discardPile->addCards(drawnCards);

	//check if adding card cause bust
	if (player.getPlayArea()->isBust(chosenCard)) {
		std::cout << "Bust! You lost all cards" << std::endl;
		//removes cards from playArea and stores in discardPile
		player.getPlayArea()->moveAllCardsTo(game.getDiscardPile()->getCards());
		//The stolen card add into discardPile
		game.getDiscardPile()->addCard(chosenCard);
		player.setBusted(true);
	}
	else {
		//add card into playArea and new card plays its ability		
		player.getPlayArea()->addCard(chosenCard);
		chosenCard->play(game, player);
	}

}










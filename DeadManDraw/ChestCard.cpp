#include "ChestCard.h"
#include <iostream>
#include "PlayArea.h"
#include "DiscardPile.h"
#include "Player.h"
#include "Bank.h"
#include "Game.h"


ChestCard::ChestCard(int value) :
	Card(value, Chest)
{
}

ChestCard::~ChestCard()
{
}

std::string ChestCard::str() const
{
	return "Chest(" + std::to_string(getValue()) + ")";
}

void ChestCard::play(Game& game, Player& player)
{
	std::cout << "Chest ability: No immediate effect. If banked with a Key card, draw bonus cards from the Discard pile." << std::endl;


}

void ChestCard::willAddToBank(Game& game, Player& player)
{
	bool hasKeyCard = false;
	int currentTurn = 0;
	bool isbusted = player.hasBusted();
	VectorContainer& playAreaCards = player.getPlayArea()->getCards();

	for (Card* card : playAreaCards) {
		if (card->getType() == Key) {
			hasKeyCard = true;
			break;
		}
	}

	if (hasKeyCard) {
		
		/*std::cout << "Chest key combination activated" << std::endl;*/

			//use this number for DiscardPile
			int numCardsOfPlayArea = playAreaCards.size();
			//draw same number of cards as are in playerArea and store in vector container
			VectorContainer drawnCards = game.getDiscardPile()->drawCards(numCardsOfPlayArea);
			if (drawnCards.empty()) {
				std::cout << "No cards in Discard Pile to to get bonus cards" << std::endl;
			}
			else {
				std::cout << "Chest-key activated. Bonus cards: ";
				for (Card* card : drawnCards) {
					std::cout << "  " << card->str();

					//add cards to the bank
					player.getBank()->addCard(card);				
					
				}
				std::cout << std::endl;
			}		

		}
	
}

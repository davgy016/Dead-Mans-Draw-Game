#include "KeyCard.h"
#include <iostream>
#include "Player.h"
#include "Game.h"

KeyCard::KeyCard(int value):
	Card(value, Key)
{
}

KeyCard::~KeyCard()
{
}

std::string KeyCard::str() const
{
	return "Key(" + std::to_string(getValue()) + ")";

}

void KeyCard::play(Game& game, Player& player)
{
	std::cout << "Key ability: No immediate effect. If banked with a Chest card, draw bonus cards from the Discard pile." << std::endl;

	// Check if there's a Chest card in the play area
	bool hasChestCard = false;
	VectorContainer& playAreaCards = player.getPlayArea()->getCards();

	for (Card* card : playAreaCards) {
		if (card->getType() == Chest) {
			hasChestCard = true;
			break;
		}
	}
	
}

void KeyCard::willAddToBank(Game& game, Player& player)
{
}


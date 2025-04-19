#include "CannonCard.h"
#include <iostream>
#include "Game.h"
#include "Bank.h"
#include <vector>


CannonCard::CannonCard(int value) :
	Card(value, Cannon)
{
}

CannonCard::~CannonCard()
{
	//std::cout << "Cannon Card Destroyed" << std::endl;
}


std::string CannonCard::str() const
{
	return "Cannon(" + std::to_string(getValue()) + ")";
}

void CannonCard::play(Game& game, Player& player)
{
	std::cout << "Discard the top card (i.e. the highest value) of any suit from the other player's Bank to the Discard Pile. " << std::endl;

	Player* otherPlayer = game.getOtherPlayer();
	Bank* otherBank = otherPlayer->getBank();

	//Check if player bank is empty
	if (otherBank->getCards().empty()) {
		std::cout<< "No cards available to discard from " << otherPlayer->getName() << "'s Bank" << std::endl;
		return;
	}

	//select the card
	CardType chosenType = player.selectCardTypeFromBank(game, otherPlayer);
	
	if (chosenType == Invalid) {
		return;
	}

	//remove card and add into Discard Pile
	Card* discardCard = otherBank->removeCardByType(chosenType);
	std::cout << "Shoot " << discardCard->str() <<" out from other player's bank" << std::endl;
	game.getDiscardPile()->addCard(discardCard);
	
}

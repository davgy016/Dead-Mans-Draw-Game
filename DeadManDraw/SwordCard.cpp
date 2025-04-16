#include "SwordCard.h"
#include <iostream>
#include "Game.h"
#include "Bank.h"
#include <vector>

SwordCard::SwordCard(int value):
	Card(value, Sword)
{
}

SwordCard::~SwordCard()
{
}

std::string SwordCard::str() const
{
	return "Sword(" + std::to_string(getValue()) + ")";
}

void SwordCard::play(Game& game, Player& player)
{
	std::cout << "Steal the top card (i.e. the highest value) of any suit from the other player’s Bank into your Play Area. You must select one card. " << std::endl;

	Player* otherPlayer = game.getOtherPlayer();
	Bank* otherBank = otherPlayer->getBank();

	//Check if player bank is empty
	if (otherBank->getCards().empty()) {
		std::cout << "No cards available to discard from " << otherPlayer->getName() << "'s Bank" << std::endl;
		return;
	}

	//select the card
	CardType chosenType = player.selectCardTypeFromBank(game, otherPlayer);

	if (chosenType == Invalid) {
		return;
	}	

	//remove chosen suit card with highest value from player's bank and store in new card
	Card* cardToSteal = otherBank->removeCard(chosenType);
	if(!cardToSteal) {
		std::cout << "Fail to steal card" << std::endl;
		return;
	}
	std::cout << "Played " << cardToSteal->str() << " from "<<otherPlayer->getName()<<" Bank into your Play Area" << std::endl;
	//check if adding card cause bust
	if (player.getPlayArea()->isBust(cardToSteal)) {
		std::cout << "Bust! You lost all cards" << std::endl;
		//removes cards from playArea and stores in discardPile
		player.getPlayArea()->moveAllCardsTo(game.getDiscardPile()->getCards());
		//The stolen card add into discardPile
		game.getDiscardPile()->addCard(cardToSteal);
		player.setBusted(true);
	}
	else {
		player.getPlayArea()->addCard(cardToSteal);
	}
	
}

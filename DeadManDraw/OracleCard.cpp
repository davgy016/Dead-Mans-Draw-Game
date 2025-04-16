#include "OracleCard.h"
#include <iostream>
#include "Player.h"
#include "Game.h"
#include "Deck.h"

OracleCard::OracleCard(int value):
	Card(value, Oracle)
{
}

OracleCard::~OracleCard()
{
}

std::string OracleCard::str() const
{
	return "Oracle(" + std::to_string(getValue()) + ")";
}

void OracleCard::play(Game& game, Player& player)
{
	std::cout << "Peek at the top card of the deck before choosing whether to draw " << std::endl;

	Deck* deck = game.getDeck();

	if (deck->size()==0) {
		std::cout << "Deck is empty, cannot peek" << std::endl;
		return;
	}

	Card* peekCard = deck->peekCard();

	if (peekCard) {
		std::cout << "Top card of Deck is " << peekCard->str() << std::endl;
	}
	else {	
		std::cout << "Could not peek top card" << std::endl;
	}
}

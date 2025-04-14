#include "KeyCard.h"
#include <iostream>
#include "Player.h"
#include "Game.h"

KeyCard::KeyCard(int value):
	Card(value, Chest)
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
	std::cout << "Chest ability: No immediate effect. If banked with a Key card, draw bonus cards from the Discard pile." << std::endl;


}

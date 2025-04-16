#include "MermaidCard.h"
#include <iostream>
#include "Game.h"
#include "Player.h"

MermaidCard::MermaidCard(int value):
	Card(value,Mermaid)
{
}

MermaidCard::~MermaidCard()
{
}

std::string MermaidCard::str() const
{
	return "Mermaid(" + std::to_string(getValue()) + ")";
}

void MermaidCard::play(Game& game, Player& player)
{
	std::cout << "No ability but the cards have a higher point value " << std::endl;
}

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
}


std::string CannonCard::str() const
{
    return "Cannon(" + std::to_string(getValue()) + ")";
}

void CannonCard::play(Game& game, Player& player)
{
    std::cout << "Discard the top card (i.e. the highest value) of any suit from the other player’s Bank to the Discard Pile. " << std::endl;
   
}

#include "HookCard.h"
#include <iostream>
HookCard::~HookCard()
{
}

std::string HookCard::str() const
{
    return "Hook(" + std::to_string(getValue()) + ")";
}

void HookCard::play(Game& game, Player& player)
{
    std::cout<<"Play the top card (i.e. the highest value) of any suit from your Bank into your play area. You must select one card."<<std::endl;
}

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

    Player* otherPlayer = game.getOtherPlayer();
    
    if (otherPlayer->getBank()->size() == 0) {
        std::cout << "No cards to discard from " << otherPlayer->getName() << "'s Bank" << std::endl;
    }

    //get another player bank cards
    MapContainer& bankCards = otherPlayer->getBank()->getCards();

    std::cout << "Available suits to discard from " << otherPlayer->getName() << "'s Bank:" << std::endl;
    std::vector<CardType> avalableSuits;
    int index = 1;

    //if each suit has cards, then gets card type with highest value and stores in new vector of availableSuits. Then display available suits for user to choose
    //Note: in bank cards is always sorted by highest to lowest
    for (auto& pair : bankCards) {
        if (!pair.second.empty()) {
            CardType ct = pair.first;
            avalableSuits.push_back(ct);
            std::cout << index <<"  " << pair.second.front()->str() << std::endl;
            index++;
        }
    }
    //user select suit to discard
    int choice = 0;
    while (choice<0 || choice > avalableSuits.size()) {
        std::cout << "Choose a suit to discard 1-"<< avalableSuits.size() << std::endl;
        std::cin >> choice;
    }

    //get chosen suit
    CardType chosenType = avalableSuits[choice - 1];
    //remove chosen suit card with highest value from player's bank and store in new card
    Card* cardForDiscardPile=otherPlayer->getBank()->removeCard(chosenType);
    //new card will be added into DiscardPile   
    game.getDiscardPile()->addCard(cardForDiscardPile);
}

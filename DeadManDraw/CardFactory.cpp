#include "CardFactory.h"
#include "CannonCard.h"
#include "ChestCard.h"
#include "KeyCard.h"
#include "SwordCard.h"
#include "HookCard.h"
#include "OracleCard.h"
#include "MapCard.h"
#include "MermaidCard.h"
#include "KrakenCard.h"
#include <iostream>

typedef std::vector<Card*> cardCollection;

Card* CardFactory::createCard(CardType type, int value)
{
    switch (type) {
    case Cannon:
        return new CannonCard(value);
    case Chest:
        return new ChestCard(value);
    case Key:
        return new KeyCard(value);
    case Sword:
        return new SwordCard(value);
    case Hook:
        return new HookCard(value);
    case Oracle:
        return new OracleCard(value);
    case Map:
        return new MapCard(value);
    case Mermaid:
        return new MermaidCard(value);
    case Kraken:
        return new KrakenCard(value);
    default:
        std::cout << "Invalid card type" << std::endl;
        return nullptr;
        
    }
}

cardCollection CardFactory::createCardsOfType(CardType type)
{
    cardCollection cards;
    int maxValue = getMaxValue(type);
    int minValue = getMinValue(type);
    for (int value = minValue; value <= maxValue; ++value) {
        Card* card = createCard(type, value);
        cards.push_back(card);
    }
    return cards;
}

cardCollection CardFactory::createAllCards()
{
    return std::vector<Card*>();
}

int CardFactory::getMinValue(CardType type)
{
    if (type == Mermaid) {
        return 4;
    }
    return 2;
}

int CardFactory::getMaxValue(CardType type)
{
    if (type == Mermaid) {
        return 9;
    }    
    return 7;
}

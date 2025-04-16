#include "Bank.h"
#include <algorithm>
#include <iostream>

Bank::Bank(Player* player):
	_player(player),
    CardContainer<MapContainer>()
{
}

Bank::~Bank()
{
}

Player* Bank::getPlayer() const
{
	return _player;
}

void Bank::sortCardsByValue(CardType type)
{
    auto iter = cards.find(type);
    if (iter != cards.end()) {
        std::sort(iter->second.begin(), iter->second.end(), [](Card* a, Card* b) {
            return a->getValue() > b->getValue(); // Sort from highest to lowest
            });
    }
}


void Bank::addCard(Card* card)
{
	if (card == nullptr) {
		return;
	}
	cards[card->getType()].push_back(card);

	/*std::sort(cards[card->getType()].begin(), cards[card->getType()].end(), [](Card* a, Card* b) {
		return  a->getValue() < b->getValue();
		});*/

    sortCardsByValue(card->getType());
}

Card* Bank::removeCard(int index)
{

	return nullptr;
}

Card* Bank::removeCard(CardType type)
{
    auto iter = cards.find(type);
    if (iter != cards.end() && !iter->second.empty()) {
        //store cards of same suit in vector, which extract from map
        VectorContainer& typeCards = iter->second;
        //store first element(Highest value) in card
        Card* card = typeCards.front();
        //delete/remove particular suit card of highest value
        typeCards.erase(typeCards.begin());
        /*if (typeCards.empty()) {
            cards.erase(iter);
        }*/
        return card;
    }
    
    return nullptr;
}


int Bank::calculateScore()
{
    int totalScore = 0;

    for (const auto& pair : cards) {        
        int highestValue = 0;
        for (Card* card : pair.second) {
            highestValue = std::max(highestValue, card->getValue());
        }
        totalScore += highestValue;
    }

    return totalScore;
}

MapContainer& Bank::getCards()
{
	return cards;
}

Card* Bank::getTopCardOfType(CardType type)
{
	auto iter = cards.find(type);
	if (iter != cards.end() && !iter->second.empty()) {
		return iter->second.back();
	}

	return nullptr;
}

void Bank::displayBankDetails() const {
    if (cards.empty()) {
        std::cout << " 0" << std::endl;
        return;
    }
    
    for (const auto& pair : cards) {
        std::cout << "\n  ";        
        /*VectorContainer sortedCards = pair.second;
        std::sort(sortedCards.begin(), sortedCards.end(), [](Card* a, Card* b) {
            return a->getValue() > b->getValue();
            });*/

        for (Card* card : pair.second) {
            std::cout << card->str() << " ";
        }        
    }
    std::cout << std::endl;
}





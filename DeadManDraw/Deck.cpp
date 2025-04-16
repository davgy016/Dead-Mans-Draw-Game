#include "Deck.h"
#include "CannonCard.h"
#include "KeyCard.h"
#include "ChestCard.h"
#include "SwordCard.h"
#include "HookCard.h"
#include "OracleCard.h"
#include "MapCard.h"
#include "MermaidCard.h"
#include <iostream>
#include <algorithm>
#include <random>

Deck::Deck() :
	CardContainer<VectorContainer>()
{
}

Deck::~Deck()
{
	std::cout << "Deck Destoryed" << std::endl;
}

void Deck::initialise()
{
	for (int i = 2; i <= 7; i++) {		
		cards.push_back(new CannonCard(i));
		cards.push_back(new ChestCard(i));
		cards.push_back(new KeyCard(i));
		cards.push_back(new SwordCard(i));
		cards.push_back(new HookCard(i));
		cards.push_back(new OracleCard(i));
		cards.push_back(new MapCard(i));
		cards.push_back(new MermaidCard(i));

	}
}

void Deck::shuffleDeck()
{
	VectorContainer shuffleDeck{ cards.begin(), cards.end() };
	std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{ std::random_device{}() });
	std::copy(shuffleDeck.begin(), shuffleDeck.end(), cards.begin());

}

Card* Deck::peekCard() const
{
	if (cards.empty()) {
		std::cout<<"Deck is empty"<<std::endl;
		return nullptr;
	}
	return cards.back();
}

Card* Deck::removeCard() 
{
	if (cards.empty()) {
		std::cout << "Deck is empty" << std::endl;
		return nullptr;
	}
	Card* topCard = cards.back();
	cards.pop_back();
	return topCard;
}

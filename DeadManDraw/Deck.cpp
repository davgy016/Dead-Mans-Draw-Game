#include "Deck.h"
#include "CannonCard.h"
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

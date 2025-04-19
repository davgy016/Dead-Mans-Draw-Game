#include "DiscardPile.h"
#include <iostream>

using namespace std;

DiscardPile::DiscardPile() :
	CardContainer<VectorContainer>()
{
}

DiscardPile::~DiscardPile()
{
	for (Card* c : cards) {
		delete c;
	}
	cards.clear();
	cout << "Discard Pile destroyed" << endl;
}

//use this method for Cannon
void DiscardPile::addCard(Card* card)
{
	if (card != nullptr) {
		cards.push_back(card);
	}
}
//bool DiscardPile ::isEmpty() const {
//	return cards.empty();
//}

//remove multiple cards. e.g. check MapCardm, Chest-Key ability
VectorContainer DiscardPile::drawCards(int numOfCards)
{
	VectorContainer drawnCards;
	if (!cards.empty()) {

		for (int i = 0; i < numOfCards; ++i) {
			Card* card = cards.back();
			cards.pop_back();
			drawnCards.push_back(card);
		}
	}
	return drawnCards;
}

// add multiple cards. e.g when it is bust
void DiscardPile::addCards(const VectorContainer& newCards) {
	for (Card* card : newCards) {
		cards.push_back(card);
	}
}

VectorContainer& DiscardPile::getCards()
{
	return cards;
}

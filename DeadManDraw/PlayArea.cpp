#include "PlayArea.h"
#include <iostream>

PlayArea::PlayArea():
	CardContainer<VectorContainer>()
{
}

PlayArea::~PlayArea()
{
	cards.clear();
}

//add card into play area
void PlayArea::addCard(Card* card)
{
	if (card != nullptr) {
		cards.push_back(card);		
	}
}


bool PlayArea::isBust(Card* newCard) const
{
	for (Card* existingCard : cards) {
		if (existingCard->getType() == newCard->getType()) {
			return true;
		}
	}
	return false;
}

//void PlayArea::clear()
//{
//	cards.clear();
//}


//remove all cards from PlayArea when is busted and stored in target container.
void PlayArea::moveAllCardsTo(VectorContainer& container)
{
	for (Card* card : cards) {
		container.push_back(card);
	}
	cards.clear();
	
}

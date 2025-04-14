#ifndef DISCARDPILE_H
#define DISCARDPILE_H


#include "CardContainer.h"


class DiscardPile : public CardContainer< VectorContainer>
{
public:
	DiscardPile();
	~DiscardPile();

	void addCard(Card* card) override;

	//bool isEmpty() const override;

	//remove multiple cards. e.g. check MapCardm, Chest-Key ability
	VectorContainer drawCards(int count);

	// add multiple cards. e.g when it is bust
	void addCards(const VectorContainer& newCards);

	VectorContainer& getCards() override;
};


#endif // DISCARDPILE_H
#ifndef DISCARDPILE_H
#define DISCARDPILE_H


#include "CardContainer.h"


class DiscardPile : public CardContainer< VectorContainer>
{
public:
	DiscardPile();
	~DiscardPile();

	//remove multiple cards. e.g. check MapCardm, Chest-Key ability
	VectorContainer drawCards(int count);

	// add multiple cards. e.g when it is bust
	void addCards(const VectorContainer& cards);

};


#endif // DISCARDPILE_H
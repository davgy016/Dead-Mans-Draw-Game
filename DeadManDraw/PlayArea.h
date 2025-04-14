#ifndef PLAYAREA_H
#define PLAYAREA_H

#include "CardContainer.h"
class PlayArea : public CardContainer<VectorContainer>
{
public:
	PlayArea();
	~PlayArea();

	//add card into play area
	void addCard(Card* card) override;
	
	bool isBust(Card* newCard) const;

	//void clear() override;	

	//remove all cards when is busted
	void moveAllCardsTo(VectorContainer& container);
};


#endif // PLAYAREA_H
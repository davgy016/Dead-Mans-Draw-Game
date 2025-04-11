#ifndef DECK_H
#define DECK_H


#include "CardContainer.h"


class Deck : public CardContainer< VectorContainer>
{
public:
	Deck();
	~Deck();

	//create all the cards
	void initialise();
	
	void shuffle();
	
	//peek top card of Deck
	Card* peekCard()const;
	
};

#endif // DECK_H

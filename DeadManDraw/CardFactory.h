#ifndef CARDFACTORY_H
#define CARDFACTORY_H
#include "Card.h"

class CardFactory
{
public:
	CardFactory() = default;
	~CardFactory() = default;

	static Card* createCard(CardType type, int value);
	static std::vector<Card*> createCardsOfType(CardType type);

protected:
	static int getMinValue(CardType type);
	static int getMaxValue(CardType type);	

};


#endif // CARDFACTORY_H
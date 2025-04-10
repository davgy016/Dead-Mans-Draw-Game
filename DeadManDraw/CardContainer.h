#ifndef CARDCONTAINER_H
#define CARDCONTAINER_H
#include "Card.h"
#include <string>
#include <vector>

typedef std::vector<Card*> CardCollection;

class CardContainer
{
protected:
	CardCollection cards;

public:
	CardContainer();
	virtual ~CardContainer();

	virtual void addCard(Card* card);
	virtual Card* removeCard(int index);	
	virtual void drawCard();
	virtual const CardCollection& getCards() const;
	virtual int size() const;
	virtual bool isEmpry() const;
	virtual Card* getTopCardOfType(CardType type);
	virtual void clear();




};

#endif // CARDCONTAINER_H

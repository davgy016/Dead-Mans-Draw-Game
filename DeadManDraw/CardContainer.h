#ifndef CARDCONTAINER_H
#define CARDCONTAINER_H
#include "Card.h"
#include <string>
#include <vector>
#include <map>

typedef std::vector<Card*> VectorContainer;
typedef std::map<CardType, std::vector<Card*>> MapContainer;

template<typename ContainerType>

class CardContainer
{
protected:
	ContainerType cards;

public:
	CardContainer() {};
	virtual ~CardContainer() = 0;

	virtual void addCard(Card* card) {};
	//virtual Card* removeCard(int index) { return nullptr; }
	virtual Card* removeCardByType(CardType type) { return nullptr; };
	virtual Card* removeCard() { return nullptr; };
	virtual int size() const { return cards.size(); }
	//virtual bool isEmpty() const { return cards.empty(); }
	virtual Card* getTopCardOfType(CardType type) { return nullptr; }
	//virtual void clear() {};
	virtual ContainerType& getCards() { return cards; }	

};
// Template destructor implementation
template<typename ContainerType>
CardContainer<ContainerType>::~CardContainer() {}


#endif // CARDCONTAINER_H

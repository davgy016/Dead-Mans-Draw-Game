#ifndef CARDCONTAINER_H
#define CARDCONTAINER_H
#include "Card.h"
#include <string>
#include <vector>
#include <map>

using VectorContainer = std::vector<Card>;
using mapContainer = std::map<CardType, std::vector<Card>>;

template<typename ContainerType>

class CardContainer
{
protected:
	ContainerType cards;

public:
	CardContainer();
	virtual ~CardContainer()=0;

	virtual void addCard(Card* card)=0;
	virtual Card* removeCard(int index) = 0;
	virtual void drawCard()=0;	
	virtual int size() const = 0;
	virtual bool isEmpty() const = 0;
	virtual Card* getTopCardOfType(CardType type) = 0;
	virtual void clear() = 0;

};

template<typename ContainerType>
inline CardContainer<ContainerType>::CardContainer()
{
}

template <typename ContainerType>
CardContainer<ContainerType>::~CardContainer(){}

#endif // CARDCONTAINER_H

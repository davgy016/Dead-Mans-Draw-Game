#include "Card.h"


Card::Card(int value, CardType type):
	_pointValue(value),
	_type(type)
{
}

Card::~Card()
{
}

int Card::getValue() const
{
	return _pointValue;
}

const CardType& Card::getType() const
{
	return _type;
}













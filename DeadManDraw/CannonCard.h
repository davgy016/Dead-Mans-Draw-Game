#ifndef CANNONCARD_H
#define CANNONCARD_H
#include "Card.h"
#include <iostream>

class CannonCard : public Card
{
public:
	CannonCard(int value);
	~CannonCard();		
	
	std::string str() const override;
	void play(Game& game, Player& player) override;


	
};


#endif // CANNONCARD_H
#ifndef KRAKENCARD_H
#define KRAKENCARD_H

#include "Card.h"
class KrakenCard : public Card
{
public:
	KrakenCard(int value);
	~KrakenCard();

	std::string str() const override;
	void play(Game& game, Player& player) override;
};


#endif // KRAKENCARD_H
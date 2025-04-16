#ifndef HOOKCARD_H
#define HOOKCARD_H


#include "Card.h"
class HookCard : public Card

{
public:
	HookCard(int value);
	~HookCard();

	std::string str() const override;
	void play(Game& game, Player& player) override;
};

#endif // HOOKCARD_H
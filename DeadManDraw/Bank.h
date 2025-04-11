#ifndef BANK_H
#define BANK_H
#include "CardContainer.h"
#include "Player.h"



class Bank : public CardContainer<mapContainer>
{
protected:
    Player* _player;

public:

    Bank(Player* player);
    ~Bank();
    Player* getPlayer() const;
    void addCardsFromPlayeArea(mapContainer& playAreaCards);
    int calculateScore();
};


#endif // BANK_H
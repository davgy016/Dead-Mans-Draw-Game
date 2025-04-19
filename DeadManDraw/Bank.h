#ifndef BANK_H
#define BANK_H
#include "CardContainer.h"
#include "Player.h"



class Bank : public CardContainer<MapContainer>
{
public:
	Bank();
	~Bank();
	void addCard(Card* card) override;
	//Card* removeCard(int index) override;
	Card* removeCardByType(CardType type) override;
	int calculateScore();
	MapContainer& getCards() override;
	Card* getTopCardOfType(CardType type);
	void displayBankDetails() const;
	void sortCardsByValue(CardType type);

};


#endif // BANK_H
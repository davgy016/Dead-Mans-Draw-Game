#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "PlayArea.h"


class Game;
class Bank;
class Card;



class Player
{
protected:
	std::string _name;
	PlayArea* _playArea;
	Bank* _bank;
	bool _busted;


public:
	Player();
	~Player();

	//select player with a random name
	void intialise();

	const std::string& getName() const;

	PlayArea* getPlayArea()const;

	Bank* getBank() const;

	bool hasBusted() const;

	// plays the card into the play area 
	// returns true if this causes the player to bust,  
	// otherwise the card's ability is performed and this function returns false 
	bool playCard(Card* card, Game& game);

	// Bank the cards in the playe area
	void bankCards(Game& game);

	void printPlayerArea() const;

	void printBank() const;

	int getScore() const;

};

#endif //PLAYER_H


#ifndef CARD_H
#define CARD_H
#include <vector>
#include <string>
class Game;
class Player;

enum CardType { Cannon, Chest, Key, Sword, Hook, Oracle, Map, Mermaid, Kraken };

class Card
{
public:
	
	Card(int value, CardType type);
	virtual ~Card();
	
	int getValue() const;
	virtual std::string str() const = 0;
	const CardType& getType() const;
	virtual void play(Game& game, Player& player) = 0;
	virtual void willAddToBank(Game& game, Player& player) {};

protected:
	int _pointValue;
	CardType _type;
	
};


#endif //CARD_H
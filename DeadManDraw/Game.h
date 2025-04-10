#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include <vector>




class Game
{
protected:
	Deck* _deck;
	DiscardPile* _discardPile;
	std::vector<Player*> _players;
	int _currentPlayerIndex;
	int _currentRound;
	int _currentTurn;
	int _maxTurns;
	Game();
	Game& operator=(const Game&) = delete;
	Game(const Game&) = delete;

public:
	~Game();
	
	static Game& getInstance();
	void initialiseGame();
	void startGame();
	void endGame();
	Deck* getDeck()const;
	DiscardPile* getDiscardPile() const;
	Player* getCurrentPlayer() const;
	Player* getOtherPlayer() const;
	int getCurrentRound() const;
	int getCurrentTurn() const;
	void handlePlayerTurn();
	void nextPlayer();
	void handleBust(Player* player);
	void printGameState();



};

#endif // GAME_H

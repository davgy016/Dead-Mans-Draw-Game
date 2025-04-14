#include "Game.h"
#include <iostream>


Game::Game() :
	_currentPlayerIndex(0),
	_currentRound(1),
	_currentTurn(1),
	_maxTurns(20)
{
	_deck = nullptr;
	_discardPile = nullptr;
}

Game::~Game()
{
	delete _deck;
	delete _discardPile;	
	for (Player* player : _players) {
		delete player;
	}
	
}

//ensure only one game instance exists at all time
Game& Game::getInstance()
{
	static Game instance;
	return instance;
}
//initialise all necessary components for the game
void Game::initialiseGame()
{
	_deck = new Deck();
	_discardPile = new DiscardPile();

	_deck->initialise();
	_deck->shuffleDeck();
	

	_players.push_back(new Player());
	_players.push_back(new Player());

	_currentPlayerIndex = 0;
	_currentRound = 0;
	_currentTurn = 0;
}

void Game::startGame()
{
	std::cout << "Start the game" << std::endl;
	std::cout << "Players: " << _players.at(0) <<" vs " << _players.at(1) << std::endl;

	while (_currentTurn <= _maxTurns && _deck->size() > 0) {
		printGameState();
		handlePlayerTurn();
		nextPlayer();
		if (_currentPlayerIndex == 0) {
			_currentRound++;
		}
		_currentTurn++;
	}

	endGame();
}

void Game::endGame()
{
	std::cout << "\n=== GAME OVER ===" << std::endl;
	std::cout << "Final Scores:" << std::endl;

	for (Player* player : _players) {
		std::cout << player->getName() << ": " << player->getScore() << " points" << std::endl;
		player->printBank();
	}

	// Determine winner
	if (_players[0]->getScore() > _players[1]->getScore()) {
		std::cout << _players[0]->getName() << " wins!" << std::endl;
	}
	else if (_players[1]->getScore() > _players[0]->getScore()) {
		std::cout << _players[1]->getName() << " wins!" << std::endl;
	}
	else {
		std::cout << "It's a tie!" << std::endl;
	}

}

Deck* Game::getDeck() const
{
	return _deck;
}

DiscardPile* Game::getDiscardPile() const
{
	return _discardPile;
}

Player* Game::getCurrentPlayer() const
{
	return _players[_currentPlayerIndex];
}

Player* Game::getOtherPlayer() const
{
	return _players[(_currentPlayerIndex+1)%2];
}

int Game::getCurrentRound() const
{
	return _currentRound;
}

int Game::getCurrentTurn() const
{
	return _currentTurn;
}

void Game::handlePlayerTurn()
{
	
}

void Game::nextPlayer()
{	
}

void Game::handleBust(Player* player)
{
	
}

void Game::printGameState()
{
	
}

#include "Game.h"



Game::Game()
{
}

Game::~Game()
{
}

Game& Game::getInstance()
{
	static Game instance;
	return instance;
}

void Game::initialiseGame()
{
}

void Game::startGame()
{
}

void Game::endGame()
{
}

Deck* Game::getDeck() const
{
	return nullptr;
}

DiscardPile* Game::getDiscardPile() const
{
	return nullptr;
}

Player* Game::getCurrentPlayer() const
{
	return nullptr;
}

Player* Game::getOtherPlayer() const
{
	return nullptr;
}

int Game::getCurrentRound() const
{
	return 0;
}

int Game::getCurrentTurn() const
{
	return 0;
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

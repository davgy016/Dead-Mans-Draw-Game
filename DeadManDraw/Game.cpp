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
	Player* currentPlayer = getCurrentPlayer();
	bool continueTurn = true;
	bool busted = false;
	
	std::cout << currentPlayer->getName() << "'s turn" << std::endl;

	while (continueTurn && _deck->size() > 0) {
		Card* drawnCard = _deck->removeCard();
		if (drawnCard == nullptr) {
			std::cout << "Deck is empty!" << std::endl;
			break;
		}

		std::cout << "Drew: " << drawnCard->str() << std::endl;

		busted = currentPlayer->playCard(drawnCard, *this);

		if (busted==false) {
			handleBust(currentPlayer);
			break;
		}
		currentPlayer->printPlayerArea();
		std::cout << "Draw again? (y/n): ";
		std::string response;
		std::cin >> response;

		continueTurn = (response == "y" || response == "Y");

		if (!continueTurn) {
			std::cout << currentPlayer->getName() << " adds cards into Bank." << std::endl;
			currentPlayer->bankCards(*this);
			currentPlayer->printBank();
			std::cout << "Current Score: " << currentPlayer->getScore();
		}
	}
}

void Game::nextPlayer()
{
	getOtherPlayer();
}

void Game::handleBust(Player* player)
{
	std::cout << player->getName() << " busted!" << std::endl;

	VectorContainer cardsToDiscard;
	player->getPlayeAre()->moveAllCardsTo(cardsToDiscard);
}

void Game::printGameState()
{
	std::cout << "\n=== Round " << _currentRound << ", Turn " << _currentTurn << " ===" << std::endl;
	std::cout << "Deck: " << _deck->size() << " cards remaining" << std::endl;
}

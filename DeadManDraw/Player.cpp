#include "Player.h"
#include "Bank.h"
#include "PlayArea.h"
#include "Game.h"
#include <iostream>

using namespace std;

Player::Player() :
	_busted(false)
{
	_playArea = new PlayArea();
	_bank = new Bank(this);
	initialise();
}

Player::~Player()
{
	delete _playArea;
	delete _bank;
	cout << "Player destroyed" << endl;
}

void Player::initialise()
{
	std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };
	_name = names[rand() % 10];
}

const std::string& Player::getName() const
{
	return  _name;
}

PlayArea* Player::getPlayArea() const
{
	return _playArea;
}

Bank* Player::getBank() const
{
	return _bank;
}

bool Player::hasBusted() const
{
	return _busted;
}

bool Player::playCard(Card* card, Game& game)
{
	//card= game.getDeck()->removeCard();
	if (_playArea->isBust(card)) {	
		_busted = true;
		std::cout << "Bust! Drew " << card->str() << ", play area already had  this suit" << std::endl;		
		_playArea->moveAllCardsTo(game.getDiscardPile()->getCards());
		return true;
	}
	else {
		card->play(game, *this);
		_playArea->addCard(card);
		return false;
	}

}

void Player::bankCards(Game&game)
{
	VectorContainer cards = _playArea->getCards();

	for (Card* card : cards) {
		card->willAddToBank(game, *this);
	}

	for (Card* card : cards) {
		_bank->addCard(card);
	}

	_playArea->getCards().clear();

	_busted = false;
}

void Player::printPlayerArea() const
{
	std::cout << "Play Area:" << std::endl;

	VectorContainer& cards = _playArea->getCards();
	if (cards.empty()) {
		std::cout << "Empty" << std::endl;
		return;
	}
	for (Card* card : cards) {
		std::cout << card->str() << std::endl;
	}
}

void Player::printBank() const
{
	std::cout << "Bank:";
	_bank->displayBankDetails();
}

int Player::getScore() const
{
	int sumScore = _bank->calculateScore();
	return sumScore;
}

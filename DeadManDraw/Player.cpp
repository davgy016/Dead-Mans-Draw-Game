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
	intialise();
}

Player::~Player()
{
	delete _playArea;
	delete _bank;
	cout << "Player destroyed" << endl;
}

void Player::intialise()
{
	std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };
	_name = names[rand() % 10];
}

const std::string& Player::getName() const
{
	return  _name;
}

PlayArea* Player::getPlayeAre() const
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
	_playArea->addCard(card);
	if (_playArea->isBust(card)) {
		_busted = true;
		std::cout << "Bust! Drew " << card->str() << " but play area already had  this suit" << std::endl;
		return true;
	}
	else {
		card->play(game, *this);
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
	
}

void Player::printBank() const
{
	
}

int Player::getScore() const
{
	
}

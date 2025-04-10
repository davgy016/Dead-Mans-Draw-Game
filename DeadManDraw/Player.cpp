#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
{
}

Player::~Player()
{
	cout<<"Player destroyed"<<endl;
}

void Player::intialise()
{
}

const std::string& Player::getName() const
{
	
}

PlayArea* Player::getPlayeAre() const
{
	return nullptr;
}

Bank* Player::getBank() const
{
	return nullptr;
}

bool Player::hasBusted() const
{
	return false;
}

bool Player::playCard(Card* card, Game& game)
{
	return false;
}

void Player::bankCards()
{
}

void Player::printPlayerArea() const
{
}

void Player::printBank() const
{
}

int Player::getScore() const
{
	return 0;
}

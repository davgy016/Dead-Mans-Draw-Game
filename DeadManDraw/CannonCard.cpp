#include "CannonCard.h"
#include <iostream>
#include "Game.h"
#include "Bank.h"
#include <vector>


CannonCard::CannonCard(int value) :
	Card(value, Cannon)
{
}

CannonCard::~CannonCard()
{
}


std::string CannonCard::str() const
{
	return "Cannon(" + std::to_string(getValue()) + ")";
}

void CannonCard::play(Game& game, Player& player)
{
	std::cout << "Discard the top card (i.e. the highest value) of any suit from the other player’s Bank to the Discard Pile. " << std::endl;

	Player* otherPlayer = game.getOtherPlayer();

	if (otherPlayer->getBank()->size() == 0) {
		std::cout << "No cards to discard from " << otherPlayer->getName() << "'s Bank" << std::endl;
		return;
	}

	//get another player bank cards
	MapContainer& bankCards = otherPlayer->getBank()->getCards();

	std::vector<CardType> availableSuits;
	int index = 1;

	//if each suit has cards, then gets card type with highest value and stores in new vector of availableSuits. Then display available suits for user to choose
	//Note: in bank cards is always sorted by highest to lowest
	if (!bankCards.empty()) {
		std::cout << "Available suits to discard from " << otherPlayer->getName() << "'s Bank:" << std::endl;
	}
	for (auto& pair : bankCards) {
		if (!pair.second.empty()) {
			CardType ct = pair.first;
			availableSuits.push_back(ct);
			std::cout << index << "  " << pair.second.front()->str() << std::endl;
			index++;
		}
	}
	// Check if there are any available suits to discard
	if (availableSuits.empty()) {
		std::cout << "No cards available to discard from " << otherPlayer->getName() << "'s Bank" << std::endl;
		return;
	}

	//user select suit to discard
	int choice = 0;
	while (choice<1 || choice > availableSuits.size()) {
		std::cout << "Choose a suit to discard 1-" << availableSuits.size() << std::endl;
		std::cin >> choice;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			choice = 0;
			std::cout << "Invalid input. Please enter a number." << std::endl;
		}
	}

	//get chosen suit
	CardType chosenType = availableSuits[choice - 1];
	//remove chosen suit card with highest value from player's bank and store in new card
	Card* cardForDiscardPile = otherPlayer->getBank()->removeCard(chosenType);
	//new card will be added into DiscardPile   
	game.getDiscardPile()->addCard(cardForDiscardPile);
}

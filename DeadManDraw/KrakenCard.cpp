#include "KrakenCard.h"
#include <iostream>
#include "Player.h"
#include "Game.h"

KrakenCard::KrakenCard(int value):
	Card(value, Kraken)
{
}

KrakenCard::~KrakenCard()
{
}

std::string KrakenCard::str() const
{
	return "Kraken(" + std::to_string(getValue()) + ")";
}

void KrakenCard::play(Game& game, Player& player)
{
	std::cout << "Must draw and play three cards consecutively. " << std::endl;

	Deck* deck = game.getDeck();
	for (int i = 0; i < 3; ++i) {
		if (deck->size() == 0) {
			std::cout << "Deck is empty, cannot draw cards" << std::endl;
		}

		Card* drawnCard = deck->removeCard();

		if (drawnCard == nullptr) {
			break;
		}

		std::cout << "Drew " << drawnCard->str() << std::endl;

		bool busted = player.playCard(drawnCard, game);

		if (busted) {
			break;
		}
	}
}

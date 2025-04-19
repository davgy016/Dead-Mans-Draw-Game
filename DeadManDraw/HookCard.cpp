#include "HookCard.h"
#include <iostream>
#include "PlayArea.h"
#include "Player.h"
#include "Bank.h"
#include "Game.h"

HookCard::HookCard(int value):
	Card(value, Hook)

{
}

HookCard::~HookCard()

{
}

std::string HookCard::str() const
{
    return "Hook(" + std::to_string(getValue()) + ")";
}

void HookCard::play(Game& game, Player& player)
{
    std::cout<<"Play the top card (i.e. the highest value) of any suit from your Bank into your play area. You must select one card."<<std::endl;

    Bank* playerBank = player.getBank();
	

    if (playerBank->size() == 0) {
        std::cout << "No cards avalaible in your bank" << std::endl;
        return;
   }

	//select the card
	CardType chosenType = player.selectCardTypeFromBank(game, &player);

	if (chosenType == Invalid) {
		return;
	}

	//remove chosen suit card with highest value from player's bank and store in new card
	Card* cardToPlay = playerBank->removeCardByType(chosenType);
	if (!cardToPlay) {
		std::cout << "Fail to get card from bank" << std::endl;
		return;
	}

	std::cout << "Played " << cardToPlay->str() << " from your Bank into your Play Area" << std::endl;
	player.playCard(cardToPlay, game);
}

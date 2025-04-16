#include "OracleCard.h"

OracleCard::OracleCard(int value):
	Card(value, Oracle)
{
}

OracleCard::~OracleCard()
{
}

std::string OracleCard::str() const
{
	return "Oracle(" + std::to_string(getValue()) + ")";
}

void OracleCard::play(Game& game, Player& player)
{
}

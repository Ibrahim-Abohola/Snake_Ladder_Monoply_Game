#pragma once

#include "Card.h"
class CardFour : public Card
{
	//no parameters

public:
	CardFour(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardFour which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player
	// Moving the player forward to the start of the next snake. (If no snakes ahead, do
	//nothing)

	virtual ~CardFour(); // A Virtual Destructor
};


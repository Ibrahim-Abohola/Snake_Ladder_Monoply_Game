#pragma once

#include "Card.h"

class CardThree : public Card
{
	// CardThree Parameters:
	int walletAmount; // the wallet value to decrease from the player

public:
	CardThree(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardThree which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
	// Moving the player forward to the start of the next ladder. (If no ladders ahead, do
	//nothing)

	virtual ~CardThree(); // A Virtual Destructor
};


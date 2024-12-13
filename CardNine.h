#pragma once

#include "Card.h"

// [ CardNine ] Summary: Moves the player stopping on this card to a specific cell. This specific cell is
//specified when adding the card to the grid in the design mode.
// Its Parameters: Cell to be moved to

class CardNine : public Card
{
	// CardNine Parameters:
	CellPosition CellPos; // Cell to be moved to

public:
	CardNine(const CellPosition& pos); // A Constructor takes card position
	void SetCellPos(CellPosition& c);

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: Cell to be moved to

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardNine on the passed Player
	// by moving the player to the cell that is taken as data member

	virtual ~CardNine(); // A Virtual Destructor
};


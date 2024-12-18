#pragma once

#include "Card.h"

/*[CardNine] Summary: Gives the player stopping on this card the option to buy this cell and all cells
containing a card with the same number.For example, if a player chooses to buy
This cell is considered a station for a specific price.
This specific price is deducted from the player’s wallet in case he chooses to buy
the cell.
When a player lands on a cell owned by another player(indicated by the same
number), they must pay fees to the cell's owner. The cell price and fees are
specified during grid design.
Input is accepted only the first time a card with the same number is added to the
grid in design mode.For example, the user will enter the price and fees for card
10 only once during design but can add multiple card 10s afterward.
//////////////////////////////////////////////////////////////////////////
Input data :
i.Card price.
ii.Fees to pay by passing players. */

class Station : public Card
{

public:
	Station(const CellPosition& pos); // A Constructor takes card position

	virtual bool IsSet() = 0;  //pure virtual function to be overriden in all drived classes to check if the card inputs are set or not
	void BuyStation(Grid* pGrid, Player* pPlayer,int CardPrice,Player *& Owner); //Function that handles all operations regarding buying the card and it has same implementation across all drived classes 
	void PayStationFees(Grid* pGrid, Player *& pPlayer, int Fees, Player *& Owner); //Function that handles the fees that must be paid to the owner of the card and it has same implementation across all drived classes
	bool IsBought(Player* CardOwner);  //Function the checks if the card is bought or not

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: Cell to be moved to

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardNine on the passed Player
	// by moving the player to the cell that is taken as data member


	virtual ~Station(); // A Virtual Destructor
};


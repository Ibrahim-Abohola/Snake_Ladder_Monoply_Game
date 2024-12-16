#pragma once

#include "Card10__13.h"

#include <fstream>



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

class CardTen : public Card10__13
{
	// CardTen Parameters:

	//All data members are static because they are shared across all objects of that card
	static int Fees;    //data member for card fees 
	static int CardPrice;   //data member for card price 
	static Player* CardOwner; //pointer to card owner
	static int Saved;   //to make that the price and fees only saved once
	static int Loaded;  //to make sure that the price and fees only loaded once

public:
	CardTen(const CellPosition& pos); // A Constructor takes card position

	static void SetCardPrice(int);  //setter for the cardprice
	static void SetFees(int);   //setter for the cardfees
	bool IsSet() override;   //check if the inputs are set or not
	static int GetCardFees();  //getter for cardfees
	static int GetCardPrice(); //getter for cardprice
	static Player* SetOwner(Player*);  //setter for the owner
	static Player* GetOwner();  //getter for the owner of the card

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: Cell to be moved to

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardNine on the passed Player
	// by moving the player to the cell that is taken as data member


	virtual void Load(ifstream& Infile);// Saves the GameObject parameters to the file

	virtual void Save(ofstream& OutFile);// Loads and Reads the GameObject parameters from the file

	virtual void EditCard(Grid * pGrid);

	virtual ~CardTen(); // A Virtual Destructor

	virtual Card* CopyCard(CellPosition cPos);

};
#pragma once

#include "Card.h"
#include "Ladder.h"
#include <fstream>


class CardFive : public Card
{
	// CardFive Parameters:
    //no parameters

public:
	CardFive(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardFive which is: dice 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFive on the passed Player
	// Moving the player forward to the start of the next snake. (If no snakes ahead, do
	//nothing)

	virtual void Load(ifstream& Infile);// Saves the GameObject parameters to the file

	virtual void Save(ofstream& OutFile);// Loads and Reads the GameObject parameters from the file

	virtual Card* CopyCard(CellPosition cPos);

	virtual void EditCard(Grid *);

	virtual ~CardFive(); // A Virtual Destructor


};



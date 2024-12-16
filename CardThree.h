#pragma once

#include "Card.h"
#include <fstream>

class CardThree : public Card
{
	//no parameters

public:
	CardThree(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardThree which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
	// Moving the player forward to the start of the next ladder. (If no ladders ahead, do
	//nothing)

	virtual ~CardThree(); // A Virtual Destructor

	virtual Card* CopyCard(CellPosition cPos);

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile);
};


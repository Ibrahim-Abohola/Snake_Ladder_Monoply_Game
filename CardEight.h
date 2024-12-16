#pragma once

#include "Card.h"
#include <fstream>


class CardEight : public Card
{
	//no parameters

public:
	CardEight(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardFour which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player

	virtual ~CardEight(); // A Virtual Destructor

	virtual Card* CopyCard(CellPosition cPos);

	virtual void EditCard(Grid*);

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& InFile);
};



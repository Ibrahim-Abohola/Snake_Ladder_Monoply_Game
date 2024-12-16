#pragma once

#include "Card.h"


class CardTwo : public Card
{
	// CardTwo Parameters:
	int walletAmount; // the wallet value to increase from the player

public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTwo which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player
	// by incrementing the player's wallet by the walletAmount data member

	virtual ~CardTwo(); // A Virtual Destructor

	virtual Card* CopyCard(CellPosition cPos);

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile);


};

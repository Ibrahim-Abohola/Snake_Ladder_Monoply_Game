#pragma once

#include "Card.h"


class CardTwo : public Card
{
	// CardTwo Parameters:
	int WalletAmount; // the wallet value to increase from the player

public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTwo which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player
	// by incrementing the player's wallet by the walletAmount data member

	virtual void Load(ifstream& Infile);// Saves the GameObject parameters to the file

	virtual void Save(ofstream& OutFile);// Loads and Reads the GameObject parameters from the file

	virtual void EditCard();


	virtual ~CardTwo(); // A Virtual Destructor
};

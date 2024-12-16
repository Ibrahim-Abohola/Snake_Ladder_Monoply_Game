#pragma once

#include "Card.h"
#include <fstream>

class CardSix : public Card
{
	// CardSix Parameters:
	//no parameters

public:
	CardSix(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardSix which is: dice 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSix on the passed Player
	// Move back by the same number of steps that you just rolled and moved
	//already. (if you reach a ladder or a snake at the end of moving forward, take it)

	virtual void Load(ifstream& Infile);// Saves the GameObject parameters to the file

	virtual void Save(ofstream& OutFile);// Loads and Reads the GameObject parameters from the file

	virtual void EditCard();


	virtual ~CardSix(); // A Virtual Destructor

	virtual Card* CopyCard(CellPosition cPos);

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile);
};




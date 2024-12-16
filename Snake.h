#pragma once

#include "GameObject.h"

class Snake : public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the Snake's "Start Cell Position"

	CellPosition endCellPos; // here is the ladder's End Cell Position

public:

	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a Snake from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to Snake's end cell

	virtual void Load(ifstream& Infile) ;// Saves the GameObject parameters to the file

	virtual void Save(ofstream& OutFile) ;// Loads and Reads the GameObject parameters from the file

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual ~Snake(); // Virtual destructor

	//=============================================================================================//

	virtual bool IsOverLapping(GameObject* newObj);

	virtual GameObject* CopyCard(CellPosition cPos);

};
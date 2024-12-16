#pragma once

#include "Action.h"

class PasteCardAction : public Action
{
	// [Action Parameters]
	CellPosition cardPosition; // 2- cell position of the card

	// Note: These parameters should be read in ReadActionParameters()

public:
	PasteCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~PasteCardAction();


};



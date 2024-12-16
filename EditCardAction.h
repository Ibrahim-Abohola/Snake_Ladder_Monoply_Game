#pragma once

#include "Action.h"

class EditCardAction : public Action
{

	// [Action Parameters]
	CellPosition cardPosition; //  cell position of the card

public:

	EditCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~EditCardAction();
};

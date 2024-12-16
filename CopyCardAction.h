#pragma once

#include "Action.h"

class CopyCardAction : public Action
{
 
	// [Action Parameters]
	CellPosition cardPosition; // 2- cell position of the card

public:

	CopyCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~CopyCardAction();
};
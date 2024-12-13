#pragma once

#include "Action.h"

class InputDiceValue  : public Action
{

	// No parameters for this action

public:
	InputDiceValue(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputDiceValue();
};



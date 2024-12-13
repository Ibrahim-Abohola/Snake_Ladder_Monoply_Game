#pragma once

#include "Action.h"

class New : public Action
{

	// No parameters for this action

public:
	New(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~New();
};




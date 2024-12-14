#pragma once

#include "Action.h"

class SwitchToPlay : public Action
{

	// No parameters for this action

public:
	SwitchToPlay(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~SwitchToPlay();
};





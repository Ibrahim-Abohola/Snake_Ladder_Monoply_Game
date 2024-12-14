#pragma once

#include "Action.h"

class SwitchToDesign : public Action
{

	// No parameters for this action

public:
	SwitchToDesign(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~SwitchToDesign();
};




#pragma once

#include "Action.h"

class DeleteGameObjectAction : public Action
{
	CellPosition Position; // 1- cell position of the card

public:

	DeleteGameObjectAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~DeleteGameObjectAction();
};


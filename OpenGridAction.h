#pragma once

#include "Action.h"
#include <fstream>



class OpenGridAction : public Action
{
	ifstream OpenGrid;
	string FileName;

public:

	OpenGridAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads opengrid action parameters (filename)

	virtual void Execute();  //Excute opengrid action (read from the file)



	virtual ~OpenGridAction(); // Virtual Destructor
};
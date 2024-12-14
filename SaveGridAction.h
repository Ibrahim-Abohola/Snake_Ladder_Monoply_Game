#pragma once

#include "Action.h"
#include <fstream>



class SaveGridAction : public Action
{
	ofstream SaveGrid;
	string FileName;

public:

	SaveGridAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads Savegrid action parameters (filename)

	virtual void Execute();  //Excute savegrid action (write into the file)
	


	virtual ~SaveGridAction(); // Virtual Destructor
};
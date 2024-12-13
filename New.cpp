#include "New.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

New::New(ApplicationManager* pApp) : Action(pApp)
{
}

void New::ReadActionParameters()
{
	// no parameters to read from user
}

void New::Execute()
{
	Output* Op = NULL;
	Input* In = NULL;

	///TODO: Implement this function	
		(pManager->GetGrid())->~Grid();
		Grid* g = new Grid(In,Op);//not sure

}

New::~New()
{
}

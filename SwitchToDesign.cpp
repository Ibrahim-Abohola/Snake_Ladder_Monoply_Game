#include "SwitchToDesign.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

SwitchToDesign::SwitchToDesign(ApplicationManager* pApp) : Action(pApp)
{

}

void SwitchToDesign::ReadActionParameters()
{
	// no parameters to read from user
}

void SwitchToDesign::Execute()
{
	pManager->GetGrid()->GetOutput()->CreateDesignModeToolBar();

}

SwitchToDesign::~SwitchToDesign()
{
}

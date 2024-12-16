#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{ //delete if is overlapping
}

CellPosition AddLadderAction::GetstartPos()
{
	return startPos;
}

CellPosition AddLadderAction::GetendPos()
{
	return endPos;
}

void AddLadderAction::SetstartPos(int x, int y)
{
	startPos.SetVCell(x);
	startPos.SetHCell(y);
}

void AddLadderAction::SetendPos(int x, int y)
{
	endPos.SetVCell(x);
	endPos.SetHCell(y);
}



void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();
	while ((!startPos.IsValidCell()) || startPos.GetCellNum() == 1 || startPos.HCell() == 0) {
		pOut->PrintMessage("Invalid cell position, please click on a valid cell postion ");
		startPos = pIn->GetCellClicked();
	}

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	while ((!endPos.IsValidCell()) || endPos.HCell() == 8) {
		pOut->PrintMessage("Invalid cell position, please click on a valid cell postion ");
		endPos = pIn->GetCellClicked();
	}

	pOut->ClearStatusBar();

}


// Execute the action
void AddLadderAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder* pLadder = new Ladder(startPos, endPos);
	 
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	if (!pGrid->IsOverLapping(pLadder)) {

		// Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pLadder);

		// if the GameObject cannot be added

		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
		// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

	}
	else
		pGrid->PrintErrorMessage("Error: Cannot draw the sanke because it overlapps with anthor object ! Click to continue ...");

}

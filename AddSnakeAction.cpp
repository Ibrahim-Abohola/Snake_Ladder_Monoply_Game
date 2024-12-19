#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"


AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

CellPosition AddSnakeAction::GetstartPos()
{
	return startPos;
}

CellPosition AddSnakeAction::GetendPos()
{
	return endPos;
}

void AddSnakeAction::SetstartPos(int x, int y)
{
	startPos.SetVCell(x);
	startPos.SetHCell(y);
}

void AddSnakeAction::SetendPos(int x, int y)
{
	endPos.SetVCell(x);
	endPos.SetHCell(y);
}



void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();
	while ((!startPos.IsValidCell()) || startPos.GetCellNum() == 99 || startPos.GetCellNum() == 1) {
		pOut->PrintMessage("Invalid cell position, please click on a valid cell postion ");
		endPos = pIn->GetCellClicked();
	}
	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	while ((!endPos.IsValidCell()) || endPos.GetCellNum() == 1 || endPos.GetCellNum() == 99) {
		pOut->PrintMessage("Invalid cell position, please click on a valid cell postion ");
		endPos = pIn->GetCellClicked();
	}

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Snake* pSnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	if (!pGrid->IsOverLapping(pSnake)) {

		// Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pSnake);

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

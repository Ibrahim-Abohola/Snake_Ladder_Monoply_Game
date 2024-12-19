#include "DeleteGameObjectAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{

}

void DeleteGameObjectAction::ReadActionParameters()
{
	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	// 2- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("Delete GameObject Action : Click on the object that you want to delete");
	Position = pIn->GetCellClicked();
	while ((!Position.IsValidCell()) || Position.GetCellNum() == 1 || Position.GetCellNum() == 99) {
		pOut->PrintMessage("Invalid cell position, please click on a valid cell postion ");
		Position = pIn->GetCellClicked();
	}
}

void DeleteGameObjectAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();

	// 2- Check if the cell the user clicked and want to delete it's card has a card or not
	Grid* pGrid = pManager->GetGrid();
		
	if (pGrid->RemoveObjectFromCell(Position)) {
		pGrid->UpdateInterface();
		pGrid->PrintErrorMessage("Deleted successfully");
	}
	else
		pGrid->PrintErrorMessage("there is no objects to delete");

	pGrid->GetOutput()->ClearStatusBar();
	
}

DeleteGameObjectAction::~DeleteGameObjectAction()
{
}

#include "EditCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"


EditCardAction::EditCardAction(ApplicationManager* pApp) : Action(pApp)
{
}

void EditCardAction::ReadActionParameters()
{
	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("Edit Card : Click on the Card that you want to edit...");
	cardPosition = pIn->GetCellClicked();
	while ((!cardPosition.IsValidCell()) || cardPosition.GetCellNum() == 1 || cardPosition.GetCellNum() == 99) {
		pOut->PrintMessage("Invalid cell position, please click on a valid cell postion ");
		cardPosition = pIn->GetCellClicked();
	}
}

void EditCardAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();

	if (pGrid->IsCard(cardPosition)) {
		Card* pCard;
		pCard = pGrid->IsCard(cardPosition);
		pCard->EditCard(pGrid);

	}
	else {
		pGrid->PrintErrorMessage("Error: the cell has no card to edit");
	}

	pGrid->GetOutput()->ClearStatusBar();
}

EditCardAction::~EditCardAction()
{
}

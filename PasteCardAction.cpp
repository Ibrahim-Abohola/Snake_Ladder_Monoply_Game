#include "PasteCardAction.h"

#include "Input.h"
#include "Output.h"
#include "Card.h"


PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
}

void PasteCardAction::ReadActionParameters()
{
	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();



	// 2- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("Copy Card : Click on the cell that you want to paste on...");
	cardPosition = pIn->GetCellClicked();

	while ((!cardPosition.IsValidCell()) || cardPosition.GetCellNum() == 1 || cardPosition.GetCellNum() == 99) {
		pOut->PrintMessage("Invalid cell position, please click on a valid cell postion ");
		cardPosition = pIn->GetCellClicked();
	}
}

void PasteCardAction::Execute()
{

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();

	if (pGrid->GetClipboard() != NULL) {
		Card* pCard = pGrid->GetClipboard()->CopyCard(cardPosition);
		pGrid->AddObjectToCell(pCard);
		pGrid->UpdateInterface();
		pGrid->PrintErrorMessage("pasted sucsessfully");
	}
}


PasteCardAction::~PasteCardAction()
{
}
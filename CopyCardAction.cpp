#include "CopyCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"


CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
}

void CopyCardAction::ReadActionParameters()
{
	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	//cardNumber

	// 2- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("Copy Card : Click on the Card that you want to copy...");
	cardPosition = pIn->GetCellClicked();
	while ((!cardPosition.IsValidCell()) || cardPosition.GetCellNum() == 1 || cardPosition.GetCellNum() == 99) {
		pOut->PrintMessage("Invalid cell position, please click on a valid cell postion ");
		cardPosition = pIn->GetCellClicked();
	}
}

void CopyCardAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();

	if (pGrid->IsCard(cardPosition)) {

		pGrid->SetClipboard(pGrid->IsCard(cardPosition));
		pGrid->PrintErrorMessage("Copied sucsessfully");

	}
	else {
		pGrid->PrintErrorMessage("Card cannot be copied, the cell has no card to copy");
	}


}

CopyCardAction::~CopyCardAction()
{
}

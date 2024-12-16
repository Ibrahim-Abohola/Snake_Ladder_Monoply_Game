#include "CutCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{

}

void CutCardAction::ReadActionParameters()
{
	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();



	// 2- Read the "CardToCopyPos" parameter (its cell position) and set its data member
	pOut->PrintMessage("Cut Card : Click on the Card that you want to cut");
	CardToCopyPos = pIn->GetCellClicked();
	while ((!CardToCopyPos.IsValidCell()) || CardToCopyPos.GetCellNum() == 1 || CardToCopyPos.GetCellNum() == 99) {
		pOut->PrintMessage("Invalid cell position, please click on a valid cell postion");
		CardToCopyPos = pIn->GetCellClicked();
	}

	// 3- Read the "PastePos" parameter (its cell position) and set its data member
	pOut->PrintMessage("Cut Card : Click on the cell that you want to paste on");
	PastePos = pIn->GetCellClicked();
	while ((!PastePos. IsValidCell()) || PastePos.GetCellNum() == 1 || PastePos.GetCellNum() == 99) {
		pOut->PrintMessage("Invalid cell position, please click on a valid cell postion");
		PastePos = pIn->GetCellClicked();
	}

}

void CutCardAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();

	// 2- 
	Grid* pGrid = pManager->GetGrid();

	if (pGrid->IsCard(CardToCopyPos)) {

		pGrid->SetClipboard(pGrid->IsCard(CardToCopyPos));
		pGrid->RemoveObjectFromCell(CardToCopyPos);

		Card* pCard = pGrid->GetClipboard()->CopyCard(PastePos);
		pGrid->AddObjectToCell(pCard);
		pGrid->UpdateInterface();
		pGrid->PrintErrorMessage("Cut sucsessfully");
	}
	else {
		pGrid->PrintErrorMessage("Card cannot be cut, the cell has no card to cut");
	}

}

CutCardAction::~CutCardAction()
{

}

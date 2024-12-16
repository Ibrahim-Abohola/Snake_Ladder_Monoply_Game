#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThrteen.h"

AddCardAction::AddCardAction(ApplicationManager* pApp) : Action(pApp)
{
	cardNumber = -1;
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// 1- Get a Pointer to the Input / Output Interfaces
	Input* pIn = pManager->GetGrid()->GetInput();
	Output* pOut = pManager->GetGrid()->GetOutput();

	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("Enter the card number to add ");
	cardNumber = pIn->GetInteger(pOut);
	while (cardNumber < 1 || cardNumber > 13) {
		pOut->PrintMessage("Invalid cardNumber, please enter a number between 1 and 13 ");
		cardNumber = pIn->GetInteger(pOut);
	}

	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("Click on the Cell that you want to add the card to (except cell 1 or 99)");
	cardPosition = pIn->GetCellClicked();
	while ((!cardPosition.IsValidCell()) || cardPosition.GetCellNum() == 1 || cardPosition.GetCellNum() == 99) {
		pOut->PrintMessage("Invalid cell position, please click on a valid cell postion ");
		cardPosition = pIn->GetCellClicked();
	}
	// 4- Make the needed validations on the read parameters

	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddCardAction::Execute()
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();

	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card* pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;
	case 2:
		pCard = new CardTwo(cardPosition);
		break;
	case 3:
		pCard = new CardThree(cardPosition);
		break;
	case 4:
		pCard = new CardFour(cardPosition);
		break;
	case 5:
		pCard = new CardFive(cardPosition);
		break;
	case 6:
		pCard = new CardSix(cardPosition);
		break;
	/*case 7:
		pCard = new CardSeven(cardPosition);
		break;
	case 8:
		pCard = new CardEight(cardPosition);
		break;*/
	case 9:
		pCard = new CardNine(cardPosition);
		break;
	case 10:
		pCard = new CardTen(cardPosition);
		break;
	case 11:
		pCard = new CardEleven(cardPosition);
		break;
	case 12:
		pCard = new CardTwelve(cardPosition);
		break;
	case 13:
		pCard = new CardThrteen(cardPosition);
		break;

		// A- Add the remaining cases

	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid();
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pGrid);
		// C- Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pCard);

		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar

		if (!added)
			pGrid->PrintErrorMessage("Card cannot be added, the cell already has an object");

	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
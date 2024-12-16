#include "inputdicevalue.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

InputDiceValue::InputDiceValue(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceValue::ReadActionParameters()
{

	//reads the input dice value from the user and do the needed validations
	int x, y;
	string msg;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int rollingtimes = (pManager->GetGrid())->GetCurrentPlayer()->GetRollingTimes();
	if (rollingtimes) {
		//  Get the input dice value from the user
		pOut->PrintMessage("enter the value of dice from 1 to 6 :) ");
		diceNumber = pIn->GetInteger(pOut);
		pIn->GetPointClicked(x, y);
		msg = "you entered " + to_string(diceNumber);
		pOut->PrintMessage(msg);
		pIn->GetPointClicked(x, y);
		//validation on dice number the loop doesn't stop unless the user enters a valid dice number
		while (diceNumber <= 0 || diceNumber >= 6) {
			pGrid->PrintErrorMessage("You entered an invalid diceNumber, please enter a number from 1 to 6");
			diceNumber = pIn->GetInteger(pOut);
			msg = "you entered " + to_string(diceNumber);
			pOut->PrintMessage(msg);
			pIn->GetPointClicked(x, y);
		}
	}
}

void InputDiceValue::Execute()
{
	int x, y;
	ReadActionParameters();


	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
    // -- If not ended, do the following --:
	if (!(pGrid->GetEndGame())) {
		
		// 3- Get the "current" player from pGrid
		Player* pPlayer = pGrid->GetCurrentPlayer();
		// 4- Move the currentPlayer using function Move of class player
		pPlayer->Move(pGrid, diceNumber);
		// 5- Advance the current player number of pGrid
		(pManager->GetGrid())->AdvanceCurrentPlayer();
		pIn->GetPointClicked(x, y);	
	}
	else 
		return;
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

	
}

InputDiceValue::~InputDiceValue()
{
}

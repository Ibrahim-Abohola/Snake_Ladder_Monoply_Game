#include "inputdicevalue.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

InputDiceValue::InputDiceValue(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceValue::ReadActionParameters()
{
	// no parameters to read from user
}

void InputDiceValue::Execute()
{
	int x, y;
	string msg;
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	
	
// == Here are some guideline steps (numbered below) to implement this function ==

// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action

// -- If not ended, do the following --:
	if (!(pManager->GetGrid())->GetEndGame()) {
		(pManager->GetGrid())->GetOutput()->PrintMessage("enter the value of dice from 1 to 6 :) ");
		// 2- Generate a random number from 1 to 6 --> This step is done for you
		int diceNumber = (pManager->GetGrid())->GetInput()->GetInteger((pManager->GetGrid())->GetOutput());
		(pManager->GetGrid())->GetInput()->GetPointClicked(x,y);
		msg = "you entered"+ to_string(diceNumber);
		(pManager->GetGrid())->GetOutput()->PrintMessage(msg);
		(pManager->GetGrid())->GetInput()->GetPointClicked(x, y);
		if (diceNumber >= 0 && diceNumber <= 6) {
			// 3- Get the "current" player from pGrid
			(pManager->GetGrid())->GetCurrentPlayer()->Move((pManager->GetGrid()), diceNumber);
			// 4- Move the currentPlayer using function Move of class player

			// 5- Advance the current player number of pGrid
			(pManager->GetGrid())->AdvanceCurrentPlayer();
			(pManager->GetGrid())->GetInput()->GetPointClicked(x, y);
		}
	}
	else return;
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

	
}

InputDiceValue::~InputDiceValue()
{
}

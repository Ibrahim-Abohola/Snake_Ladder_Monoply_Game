#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action

	//(pManager->GetGrid())->GetCurrentPlayer()->GetCell()->GetCellPosition();

	if (pManager->GetGrid()->GetCurrentPlayer()->GetSkipped()) {
		(pManager->GetGrid())->GetCurrentPlayer()->IncrementturnCount();
		(pManager->GetGrid())->GetCurrentPlayer()->SetSkipped(false);
		(pManager->GetGrid())->AdvanceCurrentPlayer();
		return;
	}
		// -- If not ended, do the following --:
		if (!(pManager->GetGrid())->GetEndGame()) {
			// 2- Generate a random number from 1 to 6 --> This step is done for you
			srand((int)time(NULL)); // time is for different seed each run
			int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

			pManager->GetGrid()->PrintErrorMessage("the dice was rolled with dice number = " + to_string(diceNumber));
			int x, y;
			//pManager->GetGrid()->GetInput()->GetPointClicked(x, y);
			// 3- Get the "current" player from pGrid
			(pManager->GetGrid())->GetCurrentPlayer()->Move((pManager->GetGrid()), diceNumber);
			// 4- Move the currentPlayer using function Move of class player

			// 5- Advance the current player number of pGrid
			(pManager->GetGrid())->AdvanceCurrentPlayer();
		}
	
		// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
}

RollDiceAction::~RollDiceAction()
{
}

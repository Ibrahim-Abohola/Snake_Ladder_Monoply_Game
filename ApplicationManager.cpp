#include "ApplicationManager.h"

#include "Grid.h"
#include "AddLadderAction.h"
#include "AddSnakeAction.h"
#include "AddCardAction.h"
#include "RollDiceAction.h"
#include "SaveGridAction.h"
#include "OpenGridAction.h"
#include "inputdicevalue.h"
#include "NewGame.h"
#include "SwitchToPlay.h"
#include "SwitchToDesign.h"
#include "CopyCardAction.h"
#include "PasteCardAction.h"
#include "EditCardAction.h"
#include "CutCardAction.h"
#include "DeleteGameObjectAction.h"


///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;
	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;
	case ADD_CARD:
		pAct = new AddCardAction(this);
		break;
	case COPY_CARD:
		pAct = new CopyCardAction(this);
		break;
	case PASTE_CARD:
		pAct = new PasteCardAction(this);
		break;
	case SAVE_GRID:
		pAct = new SaveGridAction(this);
		break;
	case OPEN_GRID:
		pAct = new OpenGridAction(this);
		break;
	case EDIT_CARD:
		pAct = new EditCardAction(this);
		break;
	case CUT_CARD:
		pAct = new CutCardAction(this);
		break;
	case DELETE_GAME_OBJECT:
		pAct = new DeleteGameObjectAction(this);
		break;

	case EXIT:
		pGrid->ClearGrid();
		break;
	case EXIT_GAME:
		pGrid->ClearGrid();
		break;

	case TO_PLAY_MODE:
		pAct = new SwitchToPlay(this);
		break;

	case ROLL_DICE:
		pAct = new RollDiceAction(this);
		break;
	case INPUT_DICE_VALUE:
		pAct = new InputDiceValue(this);
		break;
	case NEW_GAME:
		// create an object of RollDiceAction here
		pAct = new NewGame(this);
		break;
	case TO_DESIGN_MODE:
		pAct = new SwitchToDesign(this);
		break;

		

		///TODO: Add a case for EACH Action type in the Design mode or Play mode



	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}

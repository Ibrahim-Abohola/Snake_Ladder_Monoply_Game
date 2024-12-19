
#include "OpenGridAction.h"
#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
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



OpenGridAction::OpenGridAction(ApplicationManager* pApp) : Action(pApp)
{
	// The constructor initializes the ApplicationManager pointer data member
}

OpenGridAction::~OpenGridAction()
{
}

void OpenGridAction::ReadActionParameters() {
	//takes the file name from the user
	// 1- Get a Pointer to the Input / Output Interfaces
	Input* pIn = pManager->GetGrid()->GetInput();
	Output* pOut = pManager->GetGrid()->GetOutput();
	//read the open action parameters
	pOut->PrintMessage("Enter the file name that you want to load the grid from");
	FileName = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	FileName += ".txt";
}

void OpenGridAction::Execute() {

	//first read the action parameters
 	ReadActionParameters();


	OpenGrid.open(FileName,ios::in); // opening the file to read from
	//getting a pointer to the grid
	Grid * pGrid = pManager->GetGrid(); 
	if (OpenGrid.fail()) {  //check if there is a problem when opening the file

		pGrid->PrintErrorMessage("Error, couldn't open the file");
		return;
	}

	pGrid->ClearGrid();  //clears the grid from the previous design to laod the saved one
	pGrid->GetOutput()->ClearGridArea();  //redraws the grid again


	int count_ladders = 0, count_snakes = 0,count_cards;  


	/////////////////////////////////////////////////////////////////////////////////////////////////
	///////                       Load Ladders                                            ///////////
	/////////////////////////////////////////////////////////////////////////////////////////////////


	OpenGrid >> count_ladders; 
	GameObject * pObj;     // temp pointer to created objects

	for (int i = 0;i < count_ladders && !OpenGrid.eof();i++) {  //to loop from the first line that has ladder till the last line that has ladder in the grid, added eof just to be safe
		pObj = new Ladder(-1, -1);  //create a new ladder       
		pObj->Load(OpenGrid);     //load ladder information
		pGrid->AddObjectToCell(pObj);  //add the ladder to the cell
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////
	///////                       Load Snakes                                            ///////////
	/////////////////////////////////////////////////////////////////////////////////////////////////

	OpenGrid >> count_snakes;	

	for (int i = 0;i < count_snakes && !OpenGrid.eof();i++) {   //to loop from the first line that has snake till the last line that has snake in the grid, added eof just to be safe
		pObj = new Snake(-1, -1);  //create a new snake  
		pObj->Load(OpenGrid);     //load snake information
		pGrid->AddObjectToCell(pObj);   //add the snake to the cell
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////                       Load Cards                                             //////////
	/////////////////////////////////////////////////////////////////////////////////////////////////


	OpenGrid >> count_cards;

	for (int i = 0;i < count_cards && !OpenGrid.eof();i++) { //to loop from the first line that has cards till the last line that has card in the grid, added eof just to be safe
		
		int cardnum;
		OpenGrid >> cardnum;

		switch (cardnum)
		{
		case 1:
			pObj = new CardOne(-1);
			break;
		case 2:
			pObj = new CardTwo(-1);
			break;
		case 3:
			pObj = new CardThree(-1);
			break;
		case 4:
			pObj = new CardFour(-1);
			break;
		case 5:
			pObj = new CardFive(-1);
			break;
		case 6:
			pObj = new CardSix(-1);
			break;
		case 7:
			pObj = new CardSeven(-1);
			break;
		case 8:
			pObj = new CardEight(-1);
			break;
		case 9:
			pObj = new CardNine(-1);
			break;
		case 10:
			pObj = new CardTen(-1);
			break;
		case 11:
			pObj = new CardEleven(-1);
			break;
		case 12:
			pObj = new CardTwelve(-1);
			break;
		case 13:
			pObj = new CardThrteen(-1);
			break;
		}

		pObj->Load(OpenGrid);  //load card information
		pGrid->AddObjectToCell(pObj);   //add the card to the cell
	}

	pGrid->UpdateInterface();

	OpenGrid.close();
	pGrid->PrintErrorMessage("Grid is Opened successfully");

}

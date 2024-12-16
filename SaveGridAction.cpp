
#include "SaveGridAction.h"
#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"



SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
	// The constructor initializes the ApplicationManager pointer data member
}

SaveGridAction::~SaveGridAction()
{
}

void SaveGridAction::ReadActionParameters() {
	//takes the file name from the user
	// 1- Get a Pointer to the Input / Output Interfaces
	Input * pIn = pManager->GetGrid()->GetInput();
	Output * pOut = pManager->GetGrid()->GetOutput();
	//read the save action parameters
	pOut->PrintMessage("Enter the file name that you want to save the grid into");
	FileName = pIn->GetSrting(pOut);
	FileName += ".txt";
}

void SaveGridAction::Execute() {
	ReadActionParameters();
	SaveGrid.open(FileName,ios::app); // opening the file in the append mode to write into it 
	Grid* pGrid = pManager->GetGrid();
	if (SaveGrid.fail()) {  //check if there is a problem when opening the file
		pGrid->PrintErrorMessage("Error, couldn't open the file");
		return;
	}

	pGrid->SaveAllLadders(SaveGrid); //call the function save in the grid to loop on the entire cell list and save any ladders first
	pGrid->SaveAllSnakes(SaveGrid); //call the function save in the grid to loop on the entire cell list and save any snakes after the ladders
	pGrid->SaveAllCards(SaveGrid); //call the function save in the grid to loop on the entire cell list and save any cards after the snakes


	SaveGrid.close();

	pGrid->PrintErrorMessage("Grid is Saved successfully");
	
}

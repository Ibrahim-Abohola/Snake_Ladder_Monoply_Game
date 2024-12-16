#include "CardNine.h"



CardNine::CardNine(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number 
}

CardNine::~CardNine(void)
{
}

Card* CardNine::CopyCard(CellPosition cPos)
{
	CardNine* pCard;
	pCard = new  CardNine(cPos);

	pCard->CellPos = this->CellPos;
	
	return pCard;
	

}


void CardNine::Save(ofstream & OutFile) {
	OutFile << GetCardNumber() << " " << position.GetCellNum() << " " << CellPos.GetCellNum() << endl;
}

void CardNine::Load(ifstream & InFile) {
	int  pos, cellpos;
	InFile >> pos >> cellpos;
	position = position.GetCellPositionFromNum(pos);
	CellPos = CellPos.GetCellPositionFromNum(cellpos);
}


void CardNine::SetCellPos(CellPosition& c) {
	if (c.IsValidCell())
		CellPos = c;
}

void CardNine::ReadCardParameters(Grid* pGrid)
{

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input * pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the Cellpos parameter with it
	//  print a descriptive message to the user 
	pOut->PrintMessage("New CardNine: Enter its Cell pos that the player should be moved to ");
	SetCellPos(pIn->GetCellClicked());

	// 3- Clear the status bar
	pOut->ClearStatusBar();

}

void CardNine::EditCard() {
	
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{


	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid,pPlayer);

	// 2- move the player to the passed cell pos
	int x,y;
	pGrid->PrintErrorMessage("You will be transfered to cell " + to_string(CellPos.GetCellNum()) + " ....click to continue");
	pGrid->GetInput()->GetPointClicked(x,y);
	pGrid->UpdatePlayerCell(pPlayer, CellPos);

}

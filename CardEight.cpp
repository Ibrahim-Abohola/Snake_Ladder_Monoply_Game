#include "CardEight.h"


CardEight::CardEight(const CellPosition& pos) :Card(pos)
{
	cardNumber = 8;
}


Card* CardEight::CopyCard(CellPosition cPos)
{
	CardEight* pCard = new CardEight(cPos);
	return pCard;
}

void CardEight::Save(ofstream& OutFile)
{
	OutFile << GetCardNumber() << " " << position.GetCellNum() << endl;
}

void CardEight::Load(ifstream& InFile)
{
	int  pos;
	InFile >> pos;
	position = position.GetCellPositionFromNum(pos);
}

void CardEight::EditCard(Grid* pGrid) {
	int x, y;
	pGrid->PrintErrorMessage("No parameters for this card to edit.......click to continue");
	pGrid->GetInput()->GetPointClicked(x, y);
	pGrid->GetOutput()->ClearStatusBar();
}


void CardEight::ReadCardParameters(Grid * pGrid)
{
	//no parametes for this card

}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	Card::Apply(pGrid, pPlayer);

	// 2-Gives the player  dice roll times.
	pGrid->PrintErrorMessage("You are banned from rolling the dice next turn..........click to continue");
	int x, y;
	pGrid->GetInput()->GetPointClicked(x, y);
	pPlayer->SetSkipped(true);

}

CardEight::~CardEight()
{
}


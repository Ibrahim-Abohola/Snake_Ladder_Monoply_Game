#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos) :Card(pos)
{
}


void CardSeven::EditCard(Grid* pGrid) {
	int x, y;
	pGrid->PrintErrorMessage("No parameters for this card to edit.......click to continue");
	pGrid->GetInput()->GetPointClicked(x, y);
	pGrid->GetOutput()->ClearStatusBar();
}


void CardSeven::ReadCardParameters(Grid* pGrid)
{
	//no parameters to read
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	Card::Apply(pGrid, pPlayer);

	// 2-Gives the player  dice roll times.
	
	pPlayer->SetRollingTimes(cardNumber);


}

CardSeven::~CardSeven()
{
}

Card* CardSeven::CopyCard(CellPosition cPos)
{
	CardSeven* pCard = new CardSeven(cPos);
	return pCard;
}

void CardSeven::Save(ofstream& OutFile)
{
	OutFile << GetCardNumber() << " " << position.GetCellNum() << endl;

}

void CardSeven::Load(ifstream& InFile)
{
	int  pos;
	InFile >> pos;
	position = position.GetCellPositionFromNum(pos);

}

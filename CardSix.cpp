#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (5 here)
}

CardSix::~CardSix(void)
{
}

Card* CardSix::CopyCard(CellPosition cPos)
{
	CardSix* pCard;
	pCard = new CardSix(cPos);
	return pCard;
}



void CardSix::Save(ofstream& OutFile) {
	OutFile << GetCardNumber() << " " << position.GetCellNum()  << endl;
}


void CardSix::Load(ifstream& InFile) {
	int  pos;
	InFile >> pos;
	position = position.GetCellPositionFromNum(pos);
	
}

void CardSix::EditCard(Grid * pGrid) {
	int x, y;
	pGrid->PrintErrorMessage("No parameters for this card to edit.......click to continue");
	pGrid->GetInput()->GetPointClicked(x, y);
	pGrid->GetOutput()->ClearStatusBar();

}


void CardSix::ReadCardParameters(Grid* pGrid)
{
	//nothing to do


}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Move back by the same number of steps that you just rolled and moved
	//already. (if you reach a ladder or a snake at the end of moving forward, take it)
	int z = pPlayer->GetjustRolledDiceNum();
	/*pPlayer->Move(pGrid, z);*/
	pGrid->PrintErrorMessage("You will be moved by backward your just rolling dice number");
	int newcell = pPlayer->GetCell()->GetCellPosition().GetCellNum() - z;
	if (newcell >= 1 )
		pGrid->UpdatePlayerCell(pPlayer, CellPosition::GetCellPositionFromNum(newcell));
	else
		pGrid->UpdatePlayerCell(pPlayer, CellPosition::GetCellPositionFromNum(1));

}

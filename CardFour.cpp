#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (1 here)
}

CardFour::~CardFour(void)
{
}


Card* CardFour::CopyCard(CellPosition cPos)
{
	CardFour* pCard;
	pCard = new CardFour(cPos);
	return pCard;
}

void CardFour::Save(ofstream& OutFile) {
	OutFile << GetCardNumber() << " " << position.GetCellNum() << endl;
}

void CardFour::Load(ifstream& InFile) {
	int  pos;
	InFile >> pos;
	position = position.GetCellPositionFromNum(pos);
	
}

void CardFour::EditCard(Grid * pGrid) {
	
	int x, y;
	pGrid->PrintErrorMessage("No parameters for this card to edit.......click to continue");
	pGrid->GetInput()->GetPointClicked(x, y);
	pGrid->GetOutput()->ClearStatusBar();
}

void CardFour::ReadCardParameters(Grid* pGrid)
{
	//no parameters for this card
	return;
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{


	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2-Move the player forward to the start of the next snake. (If no snakes ahead, do nothing)
	pGrid->PrintErrorMessage("You will be transfered to the start of the next snake if exist");
	Snake* s= pGrid->GetNextSnake((pPlayer->GetCell())->GetCellPosition());
	pGrid->UpdatePlayerCell(pPlayer, s->GetEndPosition());

	//apply the effect of the game object in the distination cell if exist
	if (pPlayer->GetCell()->GetGameObject())
	{
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
		pPlayer->SetstepCount(pPlayer->GetCell()->GetCellPosition().GetCellNum());
	}
}

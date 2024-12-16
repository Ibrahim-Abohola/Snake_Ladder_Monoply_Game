#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (1 here)
}

CardFour::~CardFour(void)
{
}

void CardFour::Save(ofstream& OutFile) {
	OutFile << GetCardNumber() << " " << position.GetCellNum() << endl;
}

void CardFour::Load(ifstream& InFile) {
	int  pos;
	InFile >> pos;
	position = position.GetCellPositionFromNum(pos);
	
}

void CardFour::EditCard() {
	
}

void CardFour::ReadCardParameters(Grid* pGrid)
{
	//no parameters for this card
	return;
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentiFourd in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2-Move the player forward to the start of the next snake. (If no snakes ahead, do nothing)
	Snake* s= pGrid->GetNextSnake((pPlayer->GetCell())->GetCellPosition());
	pGrid->UpdatePlayerCell(pPlayer, s->GetEndPosition());
}

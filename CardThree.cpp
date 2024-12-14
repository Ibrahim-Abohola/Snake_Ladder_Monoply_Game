#include "CardThree.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (1 here)
}

CardThree::~CardThree(void)
{
}

void CardThree::ReadCardParameters(Grid* pGrid)
{
	//no input
	return;
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentiThreed in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2-Move the player forward to the start of the next ladder. (If no ladders ahead, do
	//nothing)
	Ladder  *L = pGrid->GetNextLadder((pPlayer->GetCell())->GetCellPosition());
	pGrid->UpdatePlayerCell(pPlayer,L->GetEndPosition());//not sure if i should use this function or move ------>>>>please review it
	
}

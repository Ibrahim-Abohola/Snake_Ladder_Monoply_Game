#include "CardFive.h"

CardFive::CardFive(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
}

CardFive::~CardFive(void)
{
}

Card* CardFive::CopyCard(CellPosition cPos)
{
	CardFive* pCard;
	pCard = new CardFive(cPos);
	return pCard;

}

void CardFive::Save(ofstream& OutFile)
{
}

void CardFive::Load(ifstream& Infile)
{
}

void CardFive::ReadCardParameters(Grid* pGrid)
{
	//nothing to do

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	

	(pGrid->GetOutput())->ClearStatusBar();
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Move forward by the same number of steps that you just rolled and moved
	//already. (if you reach a ladder or a snake at the end of moving forward, take it)
	int z = pPlayer->GetjustRolledDiceNum();
	pPlayer->Move(pGrid, z);
	Ladder* l = (pPlayer->GetCell()->HasLadder());
	if (l)
	{
		l->Apply(pGrid, pPlayer);

	}
}

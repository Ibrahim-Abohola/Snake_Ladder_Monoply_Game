#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos) :Card(pos)
{
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	Card::Apply(pGrid, pPlayer);

	// 2-Gives the player  dice roll times.
	
	pPlayer->SetRollingTimes(2);


}

CardSeven::~CardSeven()
{
}

Card* CardSeven::CopyCard(CellPosition cPos)
{
	return nullptr;
}

void CardSeven::Save(ofstream& OutFile)
{
}

void CardSeven::Load(ifstream& Infile)
{
}

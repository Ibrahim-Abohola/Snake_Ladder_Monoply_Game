#include "CardEight.h"


CardEight::CardEight(const CellPosition& pos) :Card(pos)
{
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	Card::Apply(pGrid, pPlayer);

	// 2-Gives the player  dice roll times.

	pPlayer->SetRollingTimes(8);

}

CardEight::~CardEight()
{
}

Card* CardEight::CopyCard(CellPosition cPos)
{
	return nullptr;
}

void CardEight::Save(ofstream& OutFile)
{
}

void CardEight::Load(ifstream& Infile)
{
}

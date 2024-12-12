#include "Ladder.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	//  i think to check that they are the same x and h less then h 
	 
	///TODO: Do the needed validation

}

void Ladder::Draw(Output* pOut) const
{
	//if(position.VCell()!=endCellPos.VCell())
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	pGrid->GetOutput()->PrintMessage("You have reached a ladder. Click to continue ...");


	// 2- Apply the ladder's effect by moving the player to the endCellPos	
	//    Review the "pGrid" functions and decide which function can be used for that
	
	pPlayer->Move(pGrid, 5);

}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}

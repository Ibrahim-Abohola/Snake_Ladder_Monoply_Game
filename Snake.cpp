#include "Snake.h"


Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation  //check if there is any ob in the cells bet fr
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}


void Snake::Save(ofstream& OutFile) {

	OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;  //writing ladder information into the file
}

void Snake::Load(ifstream& InFile) {
	int startcell, endcell;
	InFile >> startcell >> endcell;
	position = position.GetCellPositionFromNum(startcell);
	endCellPos = endCellPos.GetCellPositionFromNum(endcell);
}


Snake::~Snake()
{
}


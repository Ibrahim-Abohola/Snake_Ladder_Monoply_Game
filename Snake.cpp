#include "Snake.h"
#include"Ladder.h"
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

	// 1- Print a message "You have reached a snake. Click to continue ..." and wait mouse click
	pGrid->GetOutput()->PrintMessage("You have reached a snake. Click to continue ...");
	// 2- Apply the snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
}

void Snake::Load(ifstream& Infile)
{
}

void Snake::Save(ofstream& OutFile)
{
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{
}

bool Snake::IsOverLapping(GameObject* newObj)
{
	bool sameCol = false;

	if (Snake* snakeObj = dynamic_cast<Snake*>(newObj)) { 	// Use dynamic_cast to check if newObj is a Ladder

		sameCol = (snakeObj->GetPosition().HCell() == this->GetPosition().HCell());// check also if they are in the same colomn 
		// must have the same horizontal coordinate

		if (sameCol) { // If the object is a snake and located in the same column, there is maybe overlap.
			// This logic ensures that snakes is drawn above or below each other without overlapping
			// so if theres is no overlapping it will return false

			// - The newObj vertical coordinates (of start and end cellposition) are entirely below this snake's vertical range
			// meaning the newObj start and end coordinates are > this snake's end coordinate.
			if (snakeObj->GetPosition().VCell() > this->GetEndPosition().VCell() &&
				snakeObj->GetEndPosition().VCell() > this->GetEndPosition().VCell())
				return false;

			// - The newObj vertical coordinates (of start and end cellposition) are entirely above this snake's vertical range
			// meaning the newObj start and end coordinates are < this snake's start coordinate.
			else if (snakeObj->GetPosition().VCell() < this->GetPosition().VCell() &&
				snakeObj->GetEndPosition().VCell() < this->GetPosition().VCell())
				return false;


			else
				return true;
		}
	}
	else if (Ladder* ladderObj = dynamic_cast<Ladder*>(newObj)) { 	// Use dynamic_cast to check if newObj is a Ladder

		sameCol = (ladderObj->GetPosition().HCell() == this->GetPosition().HCell());// check also if they are in the same colomn 

		if (sameCol && (this->GetPosition().VCell() == ladderObj->GetEndPosition().VCell() ||
			this->GetEndPosition().VCell() == ladderObj->GetPosition().VCell() ||
			this->GetPosition().VCell() == ladderObj->GetPosition().VCell()))
			return true;
		else
			return false;
	}
	else
		return false;    // If the object is not a ladder or not located in the same column, there is no overlapping.

}

GameObject* Snake::CopyCard(CellPosition cPos)
{
	return nullptr;
}


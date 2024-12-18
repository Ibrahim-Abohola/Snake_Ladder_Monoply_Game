#include "Snake.h"
#include"Ladder.h"
#include <fstream>
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
	int x, y;
	// 1- Print a message "You have reached a snake. Click to continue ..." and wait mouse click
	pGrid->GetOutput()->PrintMessage("You have reached a snake. Click to continue ...");
	pGrid->GetInput()->GetPointClicked(x, y);
	// 2- Apply the snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

	//apply the effect of the game object in the distination cell if exist
	if (pPlayer->GetCell()->GetGameObject())  
	{
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
		pPlayer->SetstepCount(pPlayer->GetCell()->GetCellPosition().GetCellNum());
	}
}

void Snake::Save(ofstream& OutFile)
{
	OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;  //writing ladder information into the file

}


void Snake::Load(ifstream & InFile)
{
	int startcell, endcell;
	InFile >> startcell >> endcell;
	position = position.GetCellPositionFromNum(startcell);
	endCellPos = endCellPos.GetCellPositionFromNum(endcell);
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


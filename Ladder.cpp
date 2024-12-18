#include "Ladder.h"
#include <fstream>
#include"Snake.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	 
	///TODO: Do the needed validation

}

void Ladder::Draw(Output* pOut) const
{
	//if(position.VCell()!=endCellPos.VCell())
	pOut->DrawLadder(position, endCellPos);
}




void Ladder::Save(ofstream & OutFile) {

	OutFile << position.GetCellNum()<<" "<<endCellPos.GetCellNum() << endl;  //writing ladder information into the file
}

void Ladder::Load(ifstream& InFile) {
	int startcell,endcell;
	InFile >> startcell >> endcell;
	position = position.GetCellPositionFromNum(startcell);
	endCellPos = endCellPos.GetCellPositionFromNum(endcell);
}
CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}



void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	pGrid->GetOutput()->PrintMessage("You have reached a ladder. Click to continue ...");
	pGrid->GetInput()->GetPointClicked(x, y);
	// 2- Apply the ladder's effect by moving the player to the endCellPos	
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

	//apply the effect of the game object in the distination cell if exist
	if (pPlayer->GetCell()->GetGameObject())  
	{
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
		pPlayer->SetstepCount(pPlayer->GetCell()->GetCellPosition().GetCellNum());
	}
}





bool Ladder::IsOverLapping(GameObject* newObj)
{
	bool sameCol = false;

	if (Ladder* ladderObj = dynamic_cast<Ladder*>(newObj)) { 	// Use dynamic_cast to check if newObj is a Ladder


		sameCol = (ladderObj->GetPosition().HCell() == this->GetPosition().HCell());// check also if they are in the same colomn 
		// must have the same horizontal coordinate

		if (sameCol) { // If the object is a ladder and located in the same column, there is maybe overlap.
			// This logic ensures that ladders is drawn above or below each other without overlapping
			// so if theres is no overlapping it will return false


			// - The newObj vertical coordinates (of start and end cellposition) are entirely below this ladder's vertical range
			// meaning the newObj start and end coordinates are > this ladder's start coordinate.
			if (ladderObj->GetPosition().VCell() > this->GetPosition().VCell() &&
				ladderObj->GetEndPosition().VCell() > this->GetPosition().VCell())
				return false;


			// - The newObj vertical coordinates (of start and end cellposition) are entirely above this ladder's vertical range
			// meaning the newObj start and end coordinates are < this ladder's end coordinate.
			else if (ladderObj->GetPosition().VCell() < this->GetEndPosition().VCell() &&
				ladderObj->GetEndPosition().VCell() < this->GetEndPosition().VCell())
				return false;


			else
				return true;
		}
	}

	else if (Snake* snakeObj = dynamic_cast<Snake*>(newObj)) { 	// Use dynamic_cast to check if newObj is a Ladder

		sameCol = (snakeObj->GetPosition().HCell() == this->GetPosition().HCell());// check also if they are in the same colomn 

		if (sameCol && (snakeObj->GetPosition().VCell() == this->GetEndPosition().VCell() ||
			snakeObj->GetEndPosition().VCell() == this->GetPosition().VCell() ||
			snakeObj->GetPosition().VCell() == this->GetPosition().VCell()))
			return true;
		else
			return false;
	}
	else
		return false;    // If the object is not a ladder or not located in the same column, there is no overlapping.
}


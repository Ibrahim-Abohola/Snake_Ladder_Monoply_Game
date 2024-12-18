#include "CardFive.h"

CardFive::CardFive(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
}

CardFive::~CardFive()
{

}

void CardFive::EditCard(Grid* pGrid) {
	int x, y;
	pGrid->PrintErrorMessage("No parameters for this card to edit.......click to continue");
	pGrid->GetInput()->GetPointClicked(x, y);
	pGrid->GetOutput()->ClearStatusBar();
}


Card* CardFive::CopyCard(CellPosition cPos)
{
	CardFive* pCard;
	pCard = new CardFive(cPos);
	return pCard;

}



void CardFive::Save(ofstream & OutFile) {
	OutFile << GetCardNumber() << " " << position.GetCellNum() << endl;
}

void CardFive::Load(ifstream& InFile) {
	int  pos;
	InFile >> pos;
	position = position.GetCellPositionFromNum(pos);
	
}



void CardFive::ReadCardParameters(Grid* pGrid)
{
	//nothing to do

}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Move forward by the same number of steps that you just rolled and moved
	//already. (if you reach a ladder or a snake at the end of moving forward, take it)
	int z = pPlayer->GetjustRolledDiceNum();
	/*pPlayer->Move(pGrid, z);*/
	pGrid->PrintErrorMessage("You will be moved forward by your just rolling dice number");
	int newcell = pPlayer->GetCell()->GetCellPosition().GetCellNum() + z;
	if(newcell <= 99)
		pGrid->UpdatePlayerCell(pPlayer, CellPosition::GetCellPositionFromNum(newcell));
	else {
		pGrid->SetEndGame(true);
		pGrid->UpdatePlayerCell(pPlayer, CellPosition::GetCellPositionFromNum(99));
		pGrid->PrintErrorMessage("Playe NO." + to_string(pPlayer->GetPlayerNum()) + " won, Congratulations!");
		pGrid->PrintErrorMessage("Better luck nect time for the other players!");
	}

	//apply the effect of the game object in the distination cell if exist
	if (pPlayer->GetCell()->GetGameObject())  
	{
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
		pPlayer->SetstepCount(pPlayer->GetCell()->GetCellPosition().GetCellNum());
	}
}

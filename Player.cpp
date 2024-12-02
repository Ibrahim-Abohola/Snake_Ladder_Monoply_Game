#include "Player.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum),justRolledDiceNum(0)
{
	this->pCell = pCell;
	SetTurnCount();

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	if (wallet < 0) {
		this->wallet = 0;
		return;
	}
	this->wallet = wallet; 
	// Make any needed validations
}

void Player::SetjustRolledDiceNum(int diceNumber) {
	if (diceNumber > 0 && diceNumber <= 6) {
		this->justRolledDiceNum = diceNumber;
		return;
	}
	this->justRolledDiceNum = 0;
}

int Player::GetjustRolledDiceNum() const {
	return justRolledDiceNum;
}

int Player::GetWallet() const
{
	return wallet;
}

void Player::SetTurnCount() {
	this->turnCount = 0;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

void Player::IncrementturnCount() {
	this->turnCount++;
}

void Player::SetstepCount(int CellNum) {
	if (CellNum > 0 && CellNum <= NumHorizontalCells * NumVerticalCells) {
		this->stepCount = CellNum;
	}
}

int Player::GetstepCount() const {
	return stepCount;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	CellPosition CellPos = pCell->GetCellPosition();
	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(CellPos, playerNum, playerColor);

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;

	CellPosition CellPos = pCell->GetCellPosition();
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(CellPos, playerNum, cellColor);

}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	IncrementturnCount();
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (GetTurnCount() == 3) {
		SetTurnCount();
		int wallet = GetWallet()  + diceNumber * 10;
		SetWallet(wallet);
		return;
	}
	// 3- Set the justRolledDiceNum with the passed diceNumber
	SetjustRolledDiceNum(diceNumber);
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	CellPosition pos;
	if (GetWallet() > 0) {
		CellPosition pos = pCell->GetCellPosition();
		pos.AddCellNum(justRolledDiceNum);
		int CellNum = pos.GetCellNumFromPosition(pos);
		SetstepCount(CellNum);
	}
	else {
		pGrid->PrintErrorMessage("Player NO." + to_string(playerNum) + " doesn't have any coins to move ");
		return;
	}
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	pGrid->UpdatePlayerCell(this, pos);
	// 6- Apply() the game object of the reached cell (if any)
	if (pCell->GetGameObject()) {
		pCell->GetGameObject()->Apply(pGrid, this);
		pos = pCell->GetCellPosition();
		SetstepCount(pos.GetCellNumFromPosition(pos));
	}

	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if (this->GetstepCount() > 99) {
		pGrid->SetEndGame(true);
		pGrid->UpdatePlayerCell(this, CellPosition::GetCellPositionFromNum(99));
		pGrid->PrintErrorMessage("Playe NO." + to_string(playerNum) + " won, Congratulations!");
		pGrid->PrintErrorMessage("Better luck nect time for the other players!");
	}
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
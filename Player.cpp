#include "Player.h"
#include "Card.h"

#include "GameObject.h"
#include "Attack.h"
#include "Ice.h"
#include "Fire.h"
#include "Lightning.h"
#include "Poison.h"


Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum),justRolledDiceNum(0)
{
	this->pCell = pCell;
	SetTurnCount(0);
	AttackCount = 0;
	SpecialAttackNum = 0;
	BurnCount = 0;
	PoisonCount = 0;
	Skip = false;
	for (int i = 0;i < 4;i++) {
		UsedAttack[i] = false;
	}
	// Make all the needed initialization or validations
	RollingTimes = 1;
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
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

void Player::SetTurnCount(int t) {
	if (t >= 0 && t <= 3)
		turnCount = t;
	else
		turnCount = 0;
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
		stepCount = CellNum;
	}
	else if (CellNum <= 0)
		stepCount = 0;
	else
		stepCount = 100;
}

int Player::GetstepCount() const {
	return stepCount;
}
int Player::GetPlayerNum() const {
	return playerNum;
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


void Player::SetSkipped() {
	Skip = true;
}

void Player::IsSkipped(Grid * pGrid) {

	//checks if the player should skip this turn 
	//in this case call advance playernum
	if (Skip) {
		Skip = false;
		IncrementturnCount();
		pGrid->PrintErrorMessage("You are banned from playing this turn");
		pGrid->AdvanceCurrentPlayer();
	}

}

void Player::SetBurnCount() {
	BurnCount += 3;
}

bool Player::IsBurned() {
	if (BurnCount > 0) {
		BurnCount--;
		SetWallet(GetWallet() - 20);
		return true;
	}
	return false;

}

void Player::SetPoisonCount() {
	PoisonCount += 3;
}

bool Player::IsPoisoned() {
	if (PoisonCount > 0) {
		PoisonCount--;
		return true;
	}
	return false;
}

bool Player::ChooseAttack(Grid * pGrid) {
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (AttackCount >= 2) {
		pOut->PrintMessage("You used all your special attacks");
		return false;
	}

	pOut->PrintMessage("Would you like to use a special attack instead of recharging (y or n)  ");
	string answer = pIn->GetSrting(pOut);
	if (answer == "Y" || answer == "y") {
		pGrid->PrintErrorMessage("Enter the number of the attack to choose (1.ice  2.fire  3.Lightning  4.poison) ");
		SpecialAttackNum = pIn->GetInteger(pOut);
		while (SpecialAttackNum < 1 || SpecialAttackNum > 4) {
			pOut->PrintMessage("Invalid Number, please enter a number from 1 to 4");
			SpecialAttackNum = pIn->GetInteger(pOut);
		}
		if (!UsedAttack[SpecialAttackNum])
			switch (SpecialAttackNum)
			{
			case 1:
				UseAttack(1, pGrid);
				UsedAttack[0] = true;
				break;
			case 2:
				UseAttack(2, pGrid);
				UsedAttack[1] = true;
				break;
			case 3:
				UseAttack(3, pGrid);
				UsedAttack[2] = true;
				break;
			case 4:
				UseAttack(4, pGrid);
				UsedAttack[3] = true;
				break;
			}
		else
		{
			pOut->PrintMessage("You used this attack befor, you can only use two unique special attacks .......click to continue");
			ChooseAttack(pGrid);
		}
		return true;
	}
	else
		return false;
}

void Player::IsLightned(Grid * pGrid) {
	pGrid->PrintErrorMessage("You will lost 20 coins from your wallet becuase anthor player used lighting attack");
	SetWallet(GetWallet() - 20);
	pGrid->UpdateInterface();
	
}

void Player::UseAttack(int attacktype,Grid* pGrid) {
	Attack* AttackType;
	switch (attacktype) {
	case 1:
		AttackType = new Ice(pGrid, this);
		break;
	case 2:
		AttackType = new Fire(pGrid, this);
		break;
	case 3:
		AttackType = new Lightning(pGrid, this);
		break;
	case 4:
		AttackType = new Poison(pGrid, this);
		break;
	}
	if (AttackType) {
		AttackCount++;
		SetTurnCount(0);

		AttackType->ExcuteAttack();  //calls the excute function of the choosen attack

		delete AttackType; //deallocating the memory 
		AttackType = NULL; //setting the pointer to null again
	
	}

}

void Player::Move(Grid* pGrid, int diceNumber)
{

	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	IncrementturnCount();
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (GetTurnCount() == 3) {
		if(!ChooseAttack(pGrid))
		SetTurnCount(0);
		int wallet = GetWallet()  + diceNumber * 10;
		SetWallet(wallet);
		return;
	}
	
	// 3- Set the justRolledDiceNum with the passed diceNumber
	if (IsPoisoned()) { //check if the palyer is poisoned
		pGrid->PrintErrorMessage("You are poisoned, you will lose 1 from your roll dice");
		SetjustRolledDiceNum(diceNumber - 1);
	}
	else
		SetjustRolledDiceNum(diceNumber);
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	CellPosition pos;
	if (GetWallet() > 0) {
		CellPosition pos = pCell->GetCellPosition();
		int CellNum = pos.GetCellNumFromPosition(pos) + justRolledDiceNum;
		SetstepCount(CellNum);
	}
	else {
		pGrid->PrintErrorMessage("Player NO." + to_string(playerNum) + " doesn't have any coins to move ");
		return;
	}
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	if (this->GetstepCount() == 100) {
		pGrid->SetEndGame(true);
		pGrid->UpdatePlayerCell(this, CellPosition::GetCellPositionFromNum(99));
		pGrid->PrintErrorMessage("Playe NO." + to_string(playerNum) + " won, Congratulations!");
		pGrid->PrintErrorMessage("Better luck nect time for the other players!");
		return;
	}
	pGrid->UpdatePlayerCell(this, CellPosition::GetCellPositionFromNum(stepCount));
	// 6- Apply() the game object of the reached cell (if any)
	if (pCell->GetGameObject()) {
		pCell->GetGameObject()->Apply(pGrid, this);
		pos = pCell->GetCellPosition();
		SetstepCount(pos.GetCellNumFromPosition(pos));
	}
	if (IsBurned()) {
		pGrid->PrintErrorMessage("You are burning, you will lose 20 coins");
		pGrid->UpdateInterface();
	}
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if (this->GetstepCount() == 100) {
		pGrid->SetEndGame(true);
		pGrid->UpdatePlayerCell(this, CellPosition::GetCellPositionFromNum(99));
		pGrid->PrintErrorMessage("Playe NO." + to_string(playerNum) + " won, Congratulations!");
		pGrid->PrintErrorMessage("Better luck nect time for the other players!");
	}
}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}


int Player::GetRollingTimes()
{
	return RollingTimes;

}

void Player::SetRollingTimes(int cardnum) 
{
	//Card* pCard = NULL;
	//pCard = dynamic_cast<Card*> (this->GetCell()->HasCard()); //check if the player on a card
	if (1) {

		if (cardnum == 8) //if on a card seven
			RollingTimes = 0;
	}
	else //at any other case
		RollingTimes = 1;
}

void Player::ResetPlayer() {

	stepCount = 0;
	wallet = 100;
	justRolledDiceNum = 0;
	SetTurnCount(0);
	AttackCount = 0;
	SpecialAttackNum = 0;
	BurnCount = 0;
	PoisonCount = 0;
	Skip = false;
	for (int i = 0;i < 4;i++) {
		UsedAttack[i] = false;
	}
}


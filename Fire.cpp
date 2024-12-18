#include "Fire.h"
#include "Player.h"
#include "Grid.h"

Fire::Fire(Grid* pgrid, Player* attacker) : Attack(pgrid, attacker)
{

}

Fire::~Fire()
{

}


void Fire::ReadAttack() {
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (AttackedPlayer) {
		pOut->PrintMessage("Enter the number of the player that you want to attack (from 0 to 3)");
		int number;
		number = pIn->GetInteger(pOut);
		while (number < 0 || number > 3 || number == Attacker->GetPlayerNum()) {  //validation on player number
			pOut->PrintMessage("You entered an invalid number, please enter a correct number (from 0 to 3) excluding your number");
		}
		AttackedPlayer = pGrid->GetPlayerWithNumber(number); //pointer to the attacked player

	}

}

void Fire::ExcuteAttack() {
	//excutes the attack by preventing the attacked player from rolling the dice the next turn
	ReadAttack();
	
	AttackedPlayer->SetBurnCount();  
}
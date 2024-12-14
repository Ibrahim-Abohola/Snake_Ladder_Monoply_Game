#include "Lightning.h"
#include "Player.h"
#include "Grid.h"

Lightning::Lightning(Grid* pgrid, Player* attacker) : Attack(pgrid, attacker)
{

}
Lightning::~Lightning() {

}


void Lightning::ReadAttack() {
	
	//doesn't have any parameters

}

void Lightning::ExcuteAttack() {
	//excutes the attack by preventing the attacked player from rolling the dice the next turn
	ReadAttack();
	pGrid->LightningAttack(Attacker);  //calls the lighting function in each player thar deducts 20 from thier wallet
}
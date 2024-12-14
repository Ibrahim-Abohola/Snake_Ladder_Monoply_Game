#include "Attack.h"

Attack::Attack(Grid * pgrid,Player * attacker) : pGrid(pgrid), Attacker(attacker)
{
	
}
Attack::~Attack() {

}

void Attack::ReadAttack() {

}
Player* Attack::GetAttacker() {
	return Attacker;
}
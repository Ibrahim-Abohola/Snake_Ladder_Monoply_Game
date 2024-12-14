#pragma once
#include "Player.h"
#include "Grid.h"

class Attack {
protected:
	Grid * pGrid;
	Player *  Attacker;
public:
	Attack(Grid * pgrid,Player * Attacker);
	Player* GetAttacker();
	virtual void ReadAttack();
	virtual void ExcuteAttack() = 0;
	virtual ~Attack();
};
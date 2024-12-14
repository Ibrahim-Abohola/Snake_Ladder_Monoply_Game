#pragma once

#include "Attack.h"

///Ice: Choose a player to prevent from rolling the next turn

class Lightning : public Attack
{
public:
	Lightning(Grid* pGrid, Player* attacker);
	virtual void ReadAttack();
	virtual void ExcuteAttack();
	~Lightning();
};








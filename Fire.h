#pragma once

#include "Attack.h"

///Ice: Choose a player to prevent from rolling the next turn

class Fire : public Attack
{
	Player* AttackedPlayer;
public:
	Fire(Grid* pGrid, Player* attacker);
	virtual void ReadAttack();
	virtual void ExcuteAttack();
	~Fire();
};








#pragma once

#include "Attack.h"

///Ice: Choose a player to prevent from rolling the next turn

class Poison : public Attack
{
	Player* AttackedPlayer;
public:
	Poison(Grid* pGrid, Player* attacker);
	virtual void ReadAttack();
	virtual void ExcuteAttack();
	~Poison();
};








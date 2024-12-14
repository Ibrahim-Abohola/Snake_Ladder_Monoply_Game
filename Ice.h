#pragma once

#include "Attack.h"

///Ice: Choose a player to prevent from rolling the next turn

class Ice : public Attack
{
	Player * AttackedPlayer;
public:
	Ice(Grid * pGrid,Player * attacker);
	virtual void ReadAttack(); 
	virtual void ExcuteAttack();
	~Ice();
};








#pragma once

#include "Grid.h"
#include "Cell.h"

class Player
{
	Cell* pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	// player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the players
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
	// and reset again when reached 3
	// it is used to indicate when to move and when to add to your wallet

	int AttackCount;  //counts the number of attacks the player has done
	int SpecialAttackNum;  //a number the user can choose from 1 to 4 
	int BurnCount;     //count the turns the player will be burned (deduct 20 from his wallet for 3 turns) 
	int PoisonCount;   //count the turns the player will be poisoned (deduct 1 from his rolldice for 5 turns)
	bool Skip;   //used when the player should skip next turn
	bool UsedAttack[4];


	int RollingTimes;

public:

	Player(Cell* pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell* cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet

	int GetTurnCount() const;		// A getter for the turnCount
	void SetTurnCount(int);            //setter to make turnCount = 0 after every three rolls
	void IncrementturnCount();      // increment turnCount after each roll
	///TODO: You can add setters and getters for data members here (if needed)

	void SetjustRolledDiceNum(int diceNumber);   // setter for rolledDiceNum 
	int  GetjustRolledDiceNum() const;           // getter for rolledDiceNum 

	void SetstepCount(int CellNum);             // setter for stepCount of the player
	int GetstepCount() const;                   // getter for stepCount of the player

	int GetPlayerNum() const;

	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======


	void SetSkipped();
	void IsSkipped(Grid*);
	void SetBurnCount();
	bool IsBurned();
	void SetPoisonCount();
	bool IsPoisoned();
	void IsLightned(Grid*);
	void ChooseAttack(Grid*);
	void UseAttack(int,Grid*);


	void Move(Grid* pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	// and Applies the Game Object's effect (if any) of the end reached cell 
	// for example, if the end cell contains a ladder, take it

	void AppendPlayerInfo(string& playersInfo) const; // Appends player's info to the input string, 
	// for example: P0(wallet, turnCount)


	int GetRollingTimes();
	void SetRollingTimes(int cardnum);
};


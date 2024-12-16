#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{

	cardNumber = 2; // set the inherited cardNumber data member with the card number (1 here)
}

CardTwo::~CardTwo(void)
{
}

Card* CardTwo::CopyCard(CellPosition cPos)
{
	CardTwo* pCard;
	pCard = new CardTwo(cPos);

	pCard->walletAmount = this->walletAmount;

	return pCard;
}

void CardTwo::Save(ofstream& OutFile)
{
}

void CardTwo::Load(ifstream& Infile)
{
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	int x, y;

	///TODO: Implement this function as mentiTwod in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	(pGrid->GetOutput()->PrintMessage("New CardTwo: Enter its wallet amount ... "));
	(pGrid->GetInput())->GetPointClicked(x, y);
	walletAmount = (pGrid->GetInput())->GetInteger(pGrid->GetOutput());
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardTwo: Enter its wallet amount ..."


	// [ Note ]:
	// In CardTwo, the only parameter of CardTwo is the "walletAmount" value to increase from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action
	(pGrid->GetOutput())->ClearStatusBar();
	// 3- Clear the status bar

}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentiTwod in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- increment the wallet of pPlayer by the walletAmount data member of CardTwo
	pPlayer->SetWallet(pPlayer->GetWallet() + walletAmount);
}


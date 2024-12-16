#include "CardTwo.h"
#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (1 here)
}

CardTwo::~CardTwo(void)
{
}

void CardTwo::Save(ofstream& OutFile) {
	OutFile << GetCardNumber() << " " << position.GetCellNum() << WalletAmount << endl;
}

void CardTwo::Load(ifstream& InFile) {
	int  pos, walletamount;
	InFile >> pos >> walletamount;
	this->position = position.GetCellPositionFromNum(pos);
	this->WalletAmount = walletamount;

}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	int x, y;

	///TODO: Implement this function as mentiTwod in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	(pGrid->GetOutput()->PrintMessage("New CardTwo: Enter its wallet amount ... "));
	(pGrid->GetInput())->GetPointClicked(x, y);
	WalletAmount = (pGrid->GetInput())->GetInteger(pGrid->GetOutput());
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

void CardTwo::EditCard() {

}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentiTwod in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- increment the wallet of pPlayer by the walletAmount data member of CardTwo
	pGrid->PrintErrorMessage("You wallet will be increased by the wallet amount of this card");
	pPlayer->SetWallet(pPlayer->GetWallet() + WalletAmount);
}


#include "CardOne.h"

CardOne::CardOne(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

CardOne::~CardOne(void)
{
}

 Card* CardOne::CopyCard(CellPosition cPos)
 {
	CardOne* pCard;
	pCard = new CardOne(cPos);

	pCard->walletAmount = this->walletAmount;

	return pCard;
}


void CardOne::Save(ofstream& OutFile) {
	OutFile << GetCardNumber() << " " << position.GetCellNum() <<WalletAmount << endl;
}

void CardOne::Load(ifstream& InFile) {
	int  pos, walletamount;
	InFile >> pos >> walletamount;
	this->position = position.GetCellPositionFromNum(pos);
	this->WalletAmount = walletamount;
	
}

void CardOne::EditCard() {
	
}



void CardOne::ReadCardParameters(Grid * pGrid)
{
	int x, y;
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	(pGrid->GetOutput()->PrintMessage("New CardOne: Enter its wallet amount ..."));
	int valid= (pGrid->GetInput())->GetInteger(pGrid->GetOutput());
	if (valid >= 0)
		WalletAmount = valid;
	else 
		WalletAmount = 0;
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	

	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action
	(pGrid->GetOutput())->ClearStatusBar();
	// 3- Clear the status bar

}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid,pPlayer);
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	pGrid->PrintErrorMessage("You wallet will be decreased by the wallet amount of this card");
	pPlayer->SetWallet(  pPlayer->GetWallet() - WalletAmount);
}

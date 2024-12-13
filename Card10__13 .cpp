#include "Card10__13.h"


Card10__13::Card10__13(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
}

Card10__13::~Card10__13(void)
{
}

bool Card10__13::IsBought(Player* CardOwner) {
	if (CardOwner)
		return true;
	return false;
}

void Card10__13::BuyCard(Grid* pGrid, Player* pPlayer,int CardPrice, Player * & Owner) {
	if (!IsBought(Owner)) {  //
		pGrid->PrintErrorMessage("Do you wish to buy the card and all cards with the same type in the grid for price = " + to_string(CardPrice) + "(y / n)");
		string buy = pGrid->GetInput()->GetSrting(pGrid->GetOutput());
		if (buy == "y" || buy =="Y") {
			if (pPlayer->GetWallet() >= CardPrice)
			{
				pPlayer->SetWallet(pPlayer->GetWallet() - CardPrice);
				Owner = pPlayer;
				pGrid->PrintErrorMessage("Congratulations, you are the owner of this type of cards from now on");
			}
			else 
			{
				pGrid->PrintErrorMessage("You don't have enough coins to buy the card ");
				IsBought(NULL);
			}
		}
		else
			IsBought(NULL);
	}

}


void Card10__13::PayCardFees(Grid * pGrid,Player * pPlayer,int Fees, Player * & Owner) {
	
	int x, y;
	if (pPlayer != Owner) {  //check if the current player is the owner
		pGrid->PrintErrorMessage("You reached a card owned by anthor player ... click to continue");
		pGrid->GetInput()->GetPointClicked(x, y);
		pGrid->PrintErrorMessage("You have to pay some fees if you wish to continue  ... click to continue");
		pGrid->GetInput()->GetPointClicked(x, y);
		pGrid->PrintErrorMessage("If you don't have the required fees you will return to your previous location ... click to continue");
		pGrid->GetInput()->GetPointClicked(x, y);
		if (pPlayer->GetWallet() >= Fees){
			pPlayer->SetWallet(pPlayer->GetWallet() - Fees); //deduct fees from the player's wallet
			Owner->SetWallet(Owner->GetWallet() + Fees);   //increasing fees to into the owner's wallet
		}
		else {
			pGrid->PrintErrorMessage("You don't have enough fees to pass the cell .....click to continue");
			pGrid->GetInput()->GetPointClicked(x, y);
		}
	}
	else {
		pGrid->PrintErrorMessage("You are the owner of the card thus no fees to pay ....click to continue");
		pGrid->GetInput()->GetPointClicked(x, y);
	}

}

void Card10__13::ReadCardParameters(Grid* pGrid)
{

}

void Card10__13::Apply(Grid* pGrid, Player* pPlayer)
{

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

}

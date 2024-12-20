#include "Station.h"


Station::Station(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
}

Station::~Station(void)
{
}



bool Station::IsBought(Player* CardOwner) {
	if (CardOwner)
		return true;
	return false;
}

void Station::BuyStation(Grid* pGrid, Player* pPlayer,int CardPrice, Player * & Owner) {
	if (!IsBought(Owner)) {  
		int x, y;
		pGrid->GetOutput()->PrintMessage("Do you wish to buy this Station and own all cards with the same type in the grid for price = " + to_string(CardPrice) + " (y / n)");
		string buy = pGrid->GetInput()->GetSrting(pGrid->GetOutput());
		if (buy == "y" || buy =="Y") {
			if (pPlayer->GetWallet() >= CardPrice)
			{
				pPlayer->SetWallet(pPlayer->GetWallet() - CardPrice);
				Owner = pPlayer;
				pGrid->PrintErrorMessage("Congratulations, you are the owner of this station from now on ");
				pGrid->GetOutput()->ClearStatusBar();
			}
			else 
			{
				pGrid->PrintErrorMessage("You don't have enough coins to buy the Station ");
				pGrid->GetOutput()->ClearStatusBar();
				IsBought(NULL);
			}
		}
		else
			IsBought(NULL);
	}

}


void Station::PayStationFees(Grid * pGrid,Player *& pPlayer,int Fees, Player * & Owner) {
	
	int x, y;
	if (pPlayer != Owner && Owner != NULL) {  //check if the current player is the owner
		pGrid->PrintErrorMessage("You reached a card owned by anthor player ... click to continue ");
		pGrid->PrintErrorMessage("You have to pay some fees if you wish to continue  ... click to continue ");
		if (pPlayer->GetWallet() >= Fees) {
			pPlayer->SetWallet(pPlayer->GetWallet() - Fees); //deduct fees from the player's wallet
			Owner->SetWallet(Owner->GetWallet() + Fees);   //increasing fees to into the owner's wallet
		}
		/*	else {
				pGrid->PrintErrorMessage("You don't have enough fees to pass the cell .....click to continue ");
				pGrid->GetInput()->GetPointClicked(x, y);
			}*/
	}
	else if (pPlayer == Owner) {
		pGrid->PrintErrorMessage("You are the owner of the card thus no fees to pay ....click to continue ");
	}
	else {
		pGrid->PrintErrorMessage("There is no owner for the station yet thus no fees to pay ...........click to continue");
	}

}

void Station::ReadCardParameters(Grid* pGrid)
{

}

void Station::Apply(Grid* pGrid, Player* pPlayer)
{

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

}

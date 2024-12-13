#include "CardEleven.h"

int CardEleven::CardPrice = 0;
int CardEleven::Fees = 0;
Player* CardEleven::CardOwner = NULL;

CardEleven::CardEleven(const CellPosition& pos) : Card10__13(pos) // set the cell position of the card
{
	cardNumber = 11; // set the inherited cardNumber data member with the card number 

}

CardEleven::~CardEleven(void)
{
}

void CardEleven::SetCardPrice(int price) {

	if (price <= 0)  //validation
		return;
	CardPrice = price;

}
void CardEleven::SetFees(int f) {
	if (f <= 0)  //validation
		return;
	Fees = f;

}
bool CardEleven::IsSet() {
	if (GetCardPrice() <= 0 || GetCardFees() <= 0)
		return false;
	return true;

}

Player* CardEleven::SetOwner(Player* pPlayer) {
	CardOwner = pPlayer;
	return CardOwner;
}

Player* CardEleven::GetOwner() {
	return CardOwner;
}

int CardEleven::GetCardFees() {
	return Fees;
}
int CardEleven::GetCardPrice() {
	return CardPrice;
}


void CardEleven::ReadCardParameters(Grid* pGrid)
{
	int x, y;
	if (!IsSet()) {
		// 1- Get a Pointer to the Input / Output Interfaces from the Grid
		Input* pIn = pGrid->GetInput();
		Output* pOut = pGrid->GetOutput();
		// 2- Read an Integer from the user using the Input class and set the Cellpos parameter with it
		//  print a descriptive message to the user 
		pOut->PrintMessage("New CardEleven: Enter its Price and Fees that the player should pay ");
		pOut->PrintMessage("CardPrice: ");
		SetCardPrice(pIn->GetInteger(pOut));
		pIn->GetPointClicked(x, y);
		pOut->PrintMessage("Fees: ");
		SetFees(pIn->GetInteger(pOut));
		pIn->GetPointClicked(x, y);
		// 3- Clear the status bar
		pOut->ClearStatusBar();
	}

}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{


	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	BuyCard(pGrid, pPlayer, GetCardPrice(), CardOwner);  //checks if the card is bought or not and wheather the player wants tp buy the catd or not
	PayCardFees(pGrid, pPlayer, GetCardFees(), CardOwner);   //if the player is not the owner it will deduct the card fees from his wallet


}

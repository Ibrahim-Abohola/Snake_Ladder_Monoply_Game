#include "CardTen.h"

int CardTen::CardPrice = 0;
int CardTen::Fees = 0;
Player * CardTen::CardOwner = NULL;

CardTen::CardTen(const CellPosition& pos) : Card10__13(pos) // set the cell position of the card
{
	cardNumber = 10; // set the inherited cardNumber data member with the card number 
	
}

CardTen::~CardTen(void)
{
}

void CardTen::SetCardPrice(int price) {

	if (price <= 0)  //validation
		return;
	CardPrice = price;

}
void CardTen::SetFees(int f) {
	if (f <= 0)  //validation
		return;
	Fees = f;

}
bool CardTen::IsSet() {
	if (GetCardPrice() <= 0 || GetCardFees() <= 0)  
		return false;
	return true;

}

Player * CardTen::SetOwner(Player * pPlayer) {
	CardOwner = pPlayer;
	return CardOwner;
}

Player * CardTen::GetOwner(){	
	return CardOwner;
}

int CardTen::GetCardFees() {
	return Fees;
}
int CardTen::GetCardPrice()  {
	return CardPrice;
}


void CardTen::ReadCardParameters(Grid* pGrid)
{
	int x, y;
	if (!IsSet()) {
		// 1- Get a Pointer to the Input / Output Interfaces from the Grid
		Input* pIn = pGrid->GetInput();
		Output* pOut = pGrid->GetOutput();
		// 2- Read an Integer from the user using the Input class and set the Cellpos parameter with it
		//  print a descriptive message to the user 
		pOut->PrintMessage("New CardTen: Enter its Price and Fees that the player should pay ");
		pOut->PrintMessage("CardPrice: ");
		SetCardPrice(pIn->GetInteger(pOut));
		pOut->PrintMessage("Fees: ");
		SetFees(pIn->GetInteger(pOut));
		// 3- Clear the status bar
		pOut->ClearStatusBar();
	}

}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{


	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	BuyCard(pGrid, pPlayer, GetCardPrice(), CardOwner);  //checks if the card is bought or not and wheather the player wants tp buy the catd or not
	PayCardFees(pGrid, pPlayer, GetCardFees(), CardOwner);   //if the player is not the owner it will deduct the card fees from his wallet
		

}

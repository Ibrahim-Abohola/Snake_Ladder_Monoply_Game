#include "CardEleven.h"


int CardEleven::CardPrice = 0;
int CardEleven::Fees = 0;
Player* CardEleven::CardOwner = NULL;
int CardEleven::Saved = 0;
int CardEleven::Loaded = 0;

CardEleven::CardEleven(const CellPosition& pos) : Card10__13(pos) // set the cell position of the card
{
	cardNumber = 11; // set the inherited cardNumber data member with the card number 

}

CardEleven::~CardEleven(void)
{
}

void CardEleven::Save(ofstream& OutFile) {
	//special card 
	//we should save its fees and price only once the first time card of that type appear in the grid
	if (Saved == 0)
	{
		OutFile << GetCardNumber() << " " << position.GetCellNum() << " " << CardPrice << " " << Fees << endl;
		Saved++;
	}
	else
		OutFile << GetCardNumber() << " " << position.GetCellNum() << endl;

}

void CardEleven::Load(ifstream& InFile) {
	int price, pos, fees;
	//special card 
	//we should load its fees and price only once the first time card of that type appear in the grid
	if (Loaded == 0) {
		InFile >> pos >> price >> fees;
		Loaded++;
		position = position.GetCellPositionFromNum(pos);
		SetCardPrice(price);
		SetFees(fees);
	}
	else
	{
		InFile >> pos;
		position = position.GetCellPositionFromNum(pos);
	}

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

Player * CardEleven::SetOwner(Player* pPlayer) {
	CardOwner = pPlayer;
	return CardOwner;
}

Player * CardEleven::GetOwner() {
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
		pOut->PrintMessage("Fees: ");
		SetFees(pIn->GetInteger(pOut));
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

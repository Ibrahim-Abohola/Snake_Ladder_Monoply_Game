
#include "CardTwelve.h"


int CardTwelve::CardPrice = 0;
int CardTwelve::Fees = 0;
Player* CardTwelve::CardOwner = NULL;
int CardTwelve::Loaded = 0;
int CardTwelve::Saved = 0;


CardTwelve::CardTwelve(const CellPosition& pos) : Station(pos) // set the cell position of the card
{
	cardNumber = 12; // set the inherited cardNumber data member with the card number 

}

CardTwelve::~CardTwelve(void)
{
}

Card* CardTwelve::CopyCard(CellPosition cPos)
{

	CardTwelve* pCard;
	pCard = new CardTwelve(cPos);

	pCard->CardPrice = this->CardPrice;
	pCard->CardOwner = this->CardOwner;
	pCard->Saved = this->Saved;
	pCard->Loaded = this->Loaded;
	pCard->Fees = this->Fees;
	return pCard;
}

void CardTwelve::SetLoaded() {
	Loaded = 0;
}

void CardTwelve::SetSaved() {
	Saved = 0;
}



void CardTwelve::Save(ofstream& OutFile) {
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


void CardTwelve::Load(ifstream& InFile) {
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


void CardTwelve::EditCard(Grid * pGrid) {
	int x, y;
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the Cellpos parameter with it
	//  print a descriptive message to the user 
	pOut->PrintMessage("Enter the new values of the Station one by on .....click to continue");
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("CardPrice: ");
	SetCardPrice(pIn->GetInteger(pOut));

	pOut->PrintMessage("Fees: ");
	SetFees(pIn->GetInteger(pOut));

	// 3- Clear the status bar
	pOut->ClearStatusBar();

}


void CardTwelve::SetCardPrice(int price) {

	if (price <= 0)  //validation
		return;
	CardPrice = price;

}
void CardTwelve::SetFees(int f) {
	if (f <= 0)  //validation
		return;
	Fees = f;

}
bool CardTwelve::IsSet() {
	if (GetCardPrice() <= 0 || GetCardFees() <= 0)
		return false;
	return true;

}

Player* CardTwelve::SetOwner(Player* pPlayer) {
	CardOwner = pPlayer;
	return CardOwner;
}

Player* CardTwelve::GetOwner() {
	return CardOwner;
}

int CardTwelve::GetCardFees() {
	return Fees;
}
int CardTwelve::GetCardPrice() {
	return CardPrice;
}


void CardTwelve::ReadCardParameters(Grid* pGrid)
{
	int x, y;
	if (!IsSet()) {
		// 1- Get a Pointer to the Input / Output Interfaces from the Grid
		Input* pIn = pGrid->GetInput();
		Output* pOut = pGrid->GetOutput();
		// 2- Read an Integer from the user using the Input class and set the Cellpos parameter with it
		//  print a descriptive message to the user 
		pOut->PrintMessage("New CardTwelve: Enter its Price and Fees that the player should pay ");
		pOut->PrintMessage("CardPrice: ");
		SetCardPrice(pIn->GetInteger(pOut));

		pOut->PrintMessage("Fees: ");
		SetFees(pIn->GetInteger(pOut));

		// 3- Clear the status bar
		pOut->ClearStatusBar();
	}

}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{


	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	BuyStation(pGrid, pPlayer, GetCardPrice(), CardOwner);  //checks if the card is bought or not and wheather the player wants tp buy the catd or not
	PayStationFees(pGrid, pPlayer, GetCardFees(), CardOwner);   //if the player is not the owner it will deduct the card fees from his wallet


}

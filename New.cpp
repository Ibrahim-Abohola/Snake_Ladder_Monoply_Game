#include "New.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

New::New(ApplicationManager* pApp) : Action(pApp)
{
}

void New::ReadActionParameters()
{
	// no parameters to read from user
}

void New::Execute()
{
	Cell* c = new Cell(8,0);
	for (int i = 0; i < MaxPlayerCount;i++) {
		pManager->GetGrid()->GetCurrentPlayer()->ClearDrawing(pManager->GetGrid()->GetOutput());
		pManager->GetGrid()->GetCurrentPlayer()->SetCell(c);
		pManager->GetGrid()->GetCurrentPlayer()->Draw(pManager->GetGrid()->GetOutput());
		pManager->GetGrid()->AdvanceCurrentPlayer();
	}
	pManager->GetGrid()->Reset();
}

New::~New()
{
}

#include "SwitchToPlay.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

SwitchToPlay::SwitchToPlay(ApplicationManager* pApp) : Action(pApp)
{
	pManager->GetGrid()->GetOutput()->CreatePlayModeToolBar();
	Cell* c = new Cell(8, 0);
	for (int i = 0; i < MaxPlayerCount; i++) {
		pManager->GetGrid()->GetCurrentPlayer()->ClearDrawing(pManager->GetGrid()->GetOutput());
		pManager->GetGrid()->GetCurrentPlayer()->SetCell(c);
		pManager->GetGrid()->GetCurrentPlayer()->Draw(pManager->GetGrid()->GetOutput());
		pManager->GetGrid()->AdvanceCurrentPlayer();
	}
	pManager->GetGrid()->Reset();//same as new
}

void SwitchToPlay::ReadActionParameters()
{
	// no parameters to read from user
}

void SwitchToPlay::Execute()
{

}

SwitchToPlay::~SwitchToPlay()
{
}

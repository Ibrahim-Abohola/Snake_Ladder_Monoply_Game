#include "SwitchToPlay.h"

#include "Grid.h"
#include "Player.h"
#include "CardTen.h"
#include "CardTwelve.h"
#include "CardEleven.h"
#include "CardThrteen.h"


#include <time.h> // used to in srand to generate random numbers with different seed

SwitchToPlay::SwitchToPlay(ApplicationManager* pApp) : Action(pApp)
{

}

void SwitchToPlay::ReadActionParameters()
{
	// no parameters to read from user
}

void SwitchToPlay::Execute()
{
	pManager->GetGrid()->GetOutput()->CreatePlayModeToolBar();
	Cell* c = new Cell(8, 0);
	for (int i = 0; i < MaxPlayerCount;i++) {
		pManager->GetGrid()->GetCurrentPlayer()->ClearDrawing(pManager->GetGrid()->GetOutput());
		pManager->GetGrid()->GetCurrentPlayer()->SetCell(c);
		pManager->GetGrid()->GetCurrentPlayer()->Draw(pManager->GetGrid()->GetOutput());
		pManager->GetGrid()->GetCurrentPlayer()->ResetPlayer();
		pManager->GetGrid()->AdvanceCurrentPlayer();
	}
	CardTen::SetOwner(NULL);
	CardEleven::SetOwner(NULL);
	CardTwelve::SetOwner(NULL);
	CardThrteen::SetOwner(NULL);
	pManager->GetGrid()->SetCurrentPlayer(0);
	pManager->GetGrid()->SetEndGame(false);
	pManager->GetGrid()->UpdateInterface();
}

SwitchToPlay::~SwitchToPlay()
{
}

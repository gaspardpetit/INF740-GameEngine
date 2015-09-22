#include "Precompiled.h"

//=============================================================================
// EXTERNAL DECLARATIONS
//=============================================================================
#include "AITask.h"
#include "Core/Game/Game.h"
#include "Core/GameManagers/IGameAI.h"

//=============================================================================
// CLASS AITask
//=============================================================================
void AITask::update()
{
	Game<IGameAI>()->update();
}

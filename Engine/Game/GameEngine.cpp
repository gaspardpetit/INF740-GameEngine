//=============================================================================
// EXTERNAL DECLARATIONS
//=============================================================================
#include "Precompiled.h"
#include "GameEngine.h"
#include "Core/Game/Game.h"
#include "Core/GameManagers/IGameLoop.h"

static GameEngineRef _instance;


bool GameEngine::init()
{
	setRef(IGameEngine::Instance());

	for (auto taskGroupIter = _tasks.begin(); taskGroupIter != _tasks.end(); ++taskGroupIter)
	{
		for (auto taskIter = taskGroupIter->second.begin(); taskIter != taskGroupIter->second.end(); ++taskIter)
		{
			(*taskIter)->init();
		}
	}
	return true;
}

bool GameEngine::run()
{
	for (auto taskGroupIter = _tasks.begin(); taskGroupIter != _tasks.end(); ++taskGroupIter)
	{
		for (auto taskIter = taskGroupIter->second.begin(); taskIter != taskGroupIter->second.end(); ++taskIter)
		{
			(*taskIter)->update();
		}
	}
		
	return Game<IGameLoop>()->exitRequested() == false;
}


bool GameEngine::cleanup()
{
	for (auto taskGroupIter = _tasks.rbegin(); taskGroupIter != _tasks.rend(); ++taskGroupIter)
	{
		for (auto taskIter = taskGroupIter->second.rbegin(); taskIter != taskGroupIter->second.rend(); ++taskIter)
		{
			(*taskIter)->cleanup();
		}
	}
	Instance().reset();
	return true;

}

void GameEngine::addTask( IGameTask *iTask, int iProprity )
{
	_tasks[iProprity].push_back(iTask);
}



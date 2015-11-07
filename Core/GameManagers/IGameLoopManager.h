#pragma once
//=============================================================================
// EXTERNAL DECLARATIONS
//=============================================================================
#include "Core/Game/IGameInterface.h"

//=============================================================================
// FORWARD DECLARATIONS
//=============================================================================

//=============================================================================
// INTERFACE IRenderManager
//=============================================================================
class IGameLoopManager: virtual public IGameInterface
{
public:
	static IdType TypeId();

public:
	virtual bool exitRequested() = 0;
	virtual void requestExit(bool iRequest) = 0;
};
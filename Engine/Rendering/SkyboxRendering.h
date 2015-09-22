#pragma once
//=============================================================================
// EXTERNAL DECLARATIONS
//=============================================================================
#include "Core/Rendering/IRenderPrimitive.h"

struct SkyboxRenderData;

class SkyboxRendering: public IRenderPrimitive
{
private:
	const SkyboxRenderData &_data;

public:
	SkyboxRendering(const SkyboxRenderData &iData);
	virtual void render(const GameObjectRef &iGameObject) override;
};

#pragma once

#include "Core/Game/IGameInterface.h"
#include "Core/GameObjects/IGameObject.h"
#include <set>

class IGameObject;

class IGameSpawner: virtual public IGameInterface
{
public:
	static IdType TypeId();

public:
	virtual void update() = 0;
	virtual void unspawn(const GameObjectRef &aActorToUnspawn) = 0;
	virtual void unspawnAll() = 0;
	virtual GameObjectRef spawn(const IGameObject::IdType &aActorID, const physx::PxTransform &aPose) = 0;
	virtual const std::set<GameObjectRef>& gameObjects() = 0;

	template<class T>
	std::shared_ptr<T> spawn(const physx::PxTransform &aInitialPose)
	{	return std::dynamic_pointer_cast<T>(spawn(T::TypeId(), aInitialPose)); }
};

typedef std::shared_ptr<IGameSpawner> GameSpawnerRef;
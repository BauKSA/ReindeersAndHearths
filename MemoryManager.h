#pragma once
#include<vector>

#include "BaseActor.h"
#include "GenericSystem.h"

#ifndef _MEMORYMANAGER_
#define _MEMORYMANAGER_

class MemoryManager {
public:
	static std::vector<GenericSystem*> systems;
	static void delete_actor(BaseActor* actor);
	static void add_system(GenericSystem* system) { MemoryManager::systems.push_back(system); };
};

#endif // !_MEMORYMANAGER_

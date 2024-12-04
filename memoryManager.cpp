#include "MemoryManager.h"

std::vector<GenericSystem*> MemoryManager::systems = {};

void MemoryManager::delete_actor(BaseActor* actor) {
	for (size_t i = 0; i < MemoryManager::systems.size(); i++) {
		auto& actors = MemoryManager::systems.at(i)->get_actors();
		for (auto& _actors : actors) {
			if (actor == _actors) {
				_actors = nullptr;
			}
		}
	}

	delete actor;
}
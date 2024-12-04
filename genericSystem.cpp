#include<iostream>

#include "GenericSystem.h"

void GenericSystem::add_actor(BaseActor* actor) {
	actors.push_back(actor);
}

void GenericSystem::clear_actors(int index) {
	if (index >= 0 && index < actors.size()) {
		actors.erase(actors.begin() + index);
	}

	actors.erase(
		std::remove_if(actors.begin(), actors.end(), [](BaseActor* ptr) { return ptr == nullptr; }),
		actors.end());
}
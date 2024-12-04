#include "Garbage.h"

void Garbage::clean() {
	for (size_t i = 0; i < bin.size(); i++) {
		MemoryManager::delete_actor(bin.at(i));
	}

	bin.clear();
	bin.shrink_to_fit();
}
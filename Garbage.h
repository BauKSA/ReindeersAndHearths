#pragma once
#include<vector>

#include "BaseActor.h"
#include "MemoryManager.h"

#ifndef _GARBAGE_
#define _GARBAGE_

class Garbage {
protected:
	std::vector<BaseActor*> bin;
public:
	Garbage() {}

	static Garbage& instance() {
		static Garbage garbage;
		return garbage;
	}

	void move_to_bin(BaseActor* actor) { bin.push_back(actor); };
	void clean();
};

#endif // !_GARBAGE_

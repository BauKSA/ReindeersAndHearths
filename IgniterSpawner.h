#pragma once
#include "LevelManager.h"
#include "Observer.h"
#include "GenericSpawner.h"
#include "Igniter.h"
#include "Utils.h"

#ifndef _IGNITERSPAWNER_
#define _IGNITERSPAWNER_

class IgniterSpawner : GenericSpawner {
public:
	IgniterSpawner() : GenericSpawner() {};

	static IgniterSpawner& instance() {
		static IgniterSpawner spawner;
		return spawner;
	}

	virtual void tick(float delta_time) override;
	virtual void spawn() override;
};

#endif // !_IGNITERSPAWNER_

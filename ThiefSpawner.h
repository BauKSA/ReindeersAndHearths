#pragma once
#include "LevelManager.h"
#include "Observer.h"
#include "GenericSpawner.h"
#include "Thief.h"
#include "Utils.h"

#ifndef _THIEFSPAWNER_
#define _THIEFSPAWNER_

class ThiefSpawner : GenericSpawner {
public:
	ThiefSpawner() : GenericSpawner() {};

	static ThiefSpawner& instance() {
		static ThiefSpawner spawner;
		return spawner;
	}

	virtual void tick(float delta_time) override;
	virtual void spawn() override;
};

#endif // !_THIEFSPAWNER_

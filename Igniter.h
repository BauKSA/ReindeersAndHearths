#pragma once
#include "Enemy.h"
#include "Utils.h"

#ifndef _IGNITER_
#define _IGNITER_

class Igniter : public Enemy {
public:
	Igniter(std::string name, float x, float y, float speed, directions direction, CollisionType collision = OVERLAP) :
		Enemy(name, x, y, speed, direction, collision) {
	}

	virtual void tick(float delta_time) override;
	void check_hearth();
};

#endif // !_IGNITER_

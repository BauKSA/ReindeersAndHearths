#pragma once
#include "AnimatedActor.h"

#ifndef _ENEMY_
#define _ENEMY_

class Enemy : public AnimatedActor {
protected:
	directions direction;
public:
	Enemy(std::string name, float x, float y, float speed, directions dir, CollisionType collision = BLOCK) :
		AnimatedActor(name, x, y, speed, collision), direction(dir) {
	}

	virtual void tick(float delta_time) override { AnimatedActor::tick(delta_time); };
};

#endif // !_ENEMY_

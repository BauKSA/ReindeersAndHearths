#pragma once
#include "AnimatedActor.h"

#ifndef _REINDEER_
#define _REINDEER_

enum ReindeerMovement {
	R_RIGHT = 0,
	R_LEFT = 1
};

class Reindeer : public AnimatedActor {
protected:
	ReindeerMovement direction;
	float spawn_delay;
	float temp_delay;
public:
	Reindeer(std::string name, float x, float y, float speed, CollisionType collision = BLOCK) :
		direction(R_RIGHT), AnimatedActor(name, x, y, speed, collision), spawn_delay(3), temp_delay(0){
	}

	void tick(float delta_time) override;
	void spawn();
};

#endif // !_REINDEER_

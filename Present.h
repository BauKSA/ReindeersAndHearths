#pragma once
#include "ShadowActor.h"

#ifndef _PRESENT_
#define _PRESENT_

class Present : public ShadowActor {
public:
	Present(std::string name, float x, float y, float speed, CollisionType collision = BLOCK) :
		ShadowActor(name, x, y, speed, collision) {
	}

	virtual void tick(float delta_time) override;
};

#endif // !_PRESENT_

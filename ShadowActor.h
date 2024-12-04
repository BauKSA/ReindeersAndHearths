#pragma once
#include "AnimatedActor.h"

#ifndef _SHADOWACTOR_
#define _SHADOWACTOR_

class ShadowActor : public AnimatedActor {
protected:
	BaseActor* shadow;
public:
	ShadowActor(std::string name, float x, float y, float speed, CollisionType collision = BLOCK) :
		AnimatedActor(name, x, y, speed, collision), shadow(nullptr) {
	}

	virtual void tick(float delta_time) override;
	void set_shadow(BaseActor* actor) {
		shadow = actor;
	};
};

#endif // !_SHADOWACTOR_

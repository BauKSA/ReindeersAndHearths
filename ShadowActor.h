#pragma once
#include "AnimatedActor.h"

#ifndef _SHADOWACTOR_
#define _SHADOWACTOR_

class ShadowActor : public AnimatedActor {
protected:
	BaseActor* shadow;
	bool frozen;
	float freeze_time;
public:
	ShadowActor(std::string name, float x, float y, float speed, CollisionType collision = BLOCK) :
		AnimatedActor(name, x, y, speed, collision), shadow(nullptr), frozen(false), freeze_time(0) {
	}

	virtual void tick(float delta_time) override;
	virtual void set_shadow_position(int x, int y, BaseActor* actor);
	void freeze(float time) { frozen = true; freeze_time = time; }
	BaseActor* get_shadow()const { return shadow; };
	void set_shadow(BaseActor* actor) {
		if (!actor) {
			shadow = nullptr;
			return;
		};

		shadow = actor;
		disable_movement();
		disable_gravity();
	};
};

#endif // !_SHADOWACTOR_

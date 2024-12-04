#pragma once
#include "AnimatedActor.h"

#ifndef _HEARTH_
#define _HEART_

enum HearthState {
	FIRE = 0,
	OFF = 1
};

class Hearth : public AnimatedActor {
protected:
	HearthState state;
	Hearth* head;
	float temp_delay;
public:
	Hearth(std::string name, float x, float y, float speed, CollisionType collision = BLOCK) :
		AnimatedActor(name, x, y, speed, collision), temp_delay(0) {
		state = OFF;
		head = nullptr;
	};

	virtual void tick(float delta_time) override;
	void fire() { state = FIRE; if (head) head->fire(); };
	void off() { state = OFF; if (head) head->off(); };
	HearthState get_state()const { return state; };
	void set_head(Hearth* _head) { head = _head; };
};

#endif // !_HEARTH_

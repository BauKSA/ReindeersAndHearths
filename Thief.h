#pragma once
#include "Enemy.h"
#include "ShadowActor.h"
#include "Player.h"

#ifndef _THIEF_
#define _THIEF_

class Thief : public Enemy {
protected:
	bool present;
	BaseActor* actual_present;
	float temp_time;
	float temp_x;
	float delta_time;
public:
	Thief(std::string name, float x, float y, float speed, directions direction) :
		Enemy(name, x, y, speed, direction, OVERLAP),
		present(false), actual_present(nullptr), delta_time(2), temp_x(x), temp_time(0.0f) {
	}

	virtual void tick(float delta_time) override;
	virtual void set_collider(BaseActor* actor) override;
	void check_collision();
	void check_player();
	void throw_present();
};

#endif // !_THIEF_

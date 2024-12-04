#pragma once
#include "AnimatedActor.h"
#include "ShadowActor.h"

#ifndef _PLAYER_
#define _PLAYER_

class Player : public AnimatedActor {
protected:
	int lives;
	bool present;
	bool frozen;
	float freeze_time;
	BaseActor* present_ptr;
public:
	Player(std::string name, float x, float y, float speed) :
		AnimatedActor(name, x, y, speed, BLOCK), lives(3), present(false), present_ptr(nullptr),
		frozen(false), freeze_time(-1.0f) {
	}

	virtual void tick(float delta_time) override;
	void check_present();
	void climb();
	void down();
	void set_collider(BaseActor* actor) override;
	bool has_present()const { return present; };
	void correct_animation();
	void set_present(BaseActor* actor) { present_ptr = actor; }
	void dispatch_present();
	void freeze(float time) { frozen = true; freeze_time = time; }
	bool is_frozen()const { return frozen; }
	int get_lives()const { return lives; }
};

#endif // !_PLAYER_

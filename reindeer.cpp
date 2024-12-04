#include "Reindeer.h"
#include "Present.h"
#include "Observer.h"
#include "GravityComponent.h"
#include "Utils.h"
#include "LevelManager.h"

void Reindeer::tick(float delta_time) {
	if (y == SCREEN_HEIGHT - 140 && x >= 300 ||
		y == SCREEN_HEIGHT - 282 && x >= 348 ||
		y == 2 && x >= 250) {
		set_animation("left");
		direction = R_LEFT;
		mright = false;
	} else if (x <= -100) {
		float num = generate_random(0, 1);
		if (num <= 0.45)
			y = SCREEN_HEIGHT - 140;
		else if (num <= 0.75)
			y = SCREEN_HEIGHT - 282;
		else
			y = 2;

		set_animation("right");
		direction = R_RIGHT;
		mleft = false;
	}

	if (x >= 55 && temp_delay >= spawn_delay) {
		spawn();

		temp_delay = 0;
		spawn_delay = generate_random(1, 10);
	} else {
		temp_delay += delta_time;
	}

	if (direction == R_RIGHT) set_movement(RIGHT);
	if (direction == R_LEFT) set_movement(LEFT);

	AnimatedActor::tick(delta_time);
}

void Reindeer::spawn() {
	Observer& obs = Observer::instance();
	if (obs.get_presents() >= LevelManager::instance().present_limit()) return;

	AnimationPaths _default;
	_default.name = "default";
	_default.paths = {
		"./sprites/presents/present-b.png"
	};

	float px = x + (sprite->width / 2.0f) - 8;
	float py = y + sprite->height + 2;

	Present* present = new Present("present", px, py, 0);
	present->initialize({ _default });

	GravityComponent* gravity = new GravityComponent;

	obs.add_actor_component(*present, *gravity);
	obs.add_actor_tick(present);
	obs.add_actor_collision(present);
	obs.sum_present();
}
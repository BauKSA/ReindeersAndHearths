#include "IgniterSpawner.h"

void IgniterSpawner::tick(float delta_time) {
	if (temp_delay >= LevelManager::instance().igniter_delay()) {
		temp_delay = 0;
		spawn();
	} else {
		temp_delay += delta_time;
	}
}

void IgniterSpawner::spawn() {
	float rndm = generate_random(0, 2);
	float y = rndm >= 1 ? SCREEN_HEIGHT - 140 : SCREEN_HEIGHT - 280;
	float x = y == SCREEN_HEIGHT - 140 ? 0 : 300;
	directions dir = x == 0 ? RIGHT : LEFT;

	AnimationPaths ign;
	ign.name = "defaukt";
	ign.paths = {
		"./sprites/enemies/igniter/igniter-left-a.png",
		"./sprites/enemies/igniter/igniter-left-b.png",
		"./sprites/enemies/igniter/igniter-left-c.png",
		"./sprites/enemies/igniter/igniter-left-d.png"
	};

	Igniter* igniter = new Igniter("igniter", x, y, 1.5f, dir);
	igniter->initialize({ ign });
	igniter->set_vspeed(1.5f);

	Observer::instance().add_actor_tick(igniter);
	Observer::instance().add_actor_collision(igniter);
}
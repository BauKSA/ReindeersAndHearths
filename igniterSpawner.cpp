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
	float rndm = generate_random(1, 5);
	float y = 0;
	if (rndm < 2.5f) y = generate_random(318, 368);
	else y = generate_random(176, 226);

	float x = rndm < 2.5f ? 0 : 300;
	directions dir = x == 0 ? RIGHT : LEFT;

	AnimationPaths ign;
	ign.name = "default";
	ign.paths = {
		"./sprites/enemies/igniter/igniter-a.png",
		"./sprites/enemies/igniter/igniter-b.png",
		"./sprites/enemies/igniter/igniter-c.png",
		"./sprites/enemies/igniter/igniter-b.png"
	};

	AnimationPaths down;
	down.name = "down";
	down.paths = {
		"./sprites/enemies/igniter/igniter-down-a.png",
		"./sprites/enemies/igniter/igniter-down-b.png"
	};

	Igniter* igniter = new Igniter("igniter", x, y, 1.5f, dir);
	igniter->initialize({ ign, down });
	igniter->set_vspeed(1.5f);

	Observer::instance().add_actor_tick(igniter);
	Observer::instance().add_actor_collision(igniter);
}
#include "ThiefSpawner.h"
#include "GravityComponent.h"

void ThiefSpawner::tick(float delta_time) {
	if (temp_delay >= LevelManager::instance().thief_delay()) {
		temp_delay = 0;
		spawn();
	}
	else {
		temp_delay += delta_time;
	}
}

void ThiefSpawner::spawn() {
	float rndm = generate_random(0, 2);
	float y = rndm >= 1 ? 343 : 169;
	float x = 325;
	directions dir = LEFT;

	std::cout << "[DEBUG] Spawn thief in " << x << ", " << y << std::endl;

	AnimationPaths right;
	right.name = "right";
	right.paths = {
		"./sprites/enemies/thief/stand-right.png",
		"./sprites/enemies/thief/walk-right.png"
	};

	AnimationPaths left;
	left.name = "left";
	left.paths = {
		"./sprites/enemies/thief/stand-left.png",
		"./sprites/enemies/thief/walk-left.png"
	};

	Thief* thief = new Thief("thief", x, y, 1.25f, dir);
	thief->initialize({ right, left });
	thief->set_vspeed(1.5f);

	GravityComponent* gravity = new GravityComponent;

	Observer::instance().add_actor_tick(thief);
	Observer::instance().add_actor_component(*thief, *gravity);
	Observer::instance().add_actor_collision(thief);
}
#include "Hearth.h"
#include "LevelManager.h"

void Hearth::tick(float delta_time) {
	if (state == FIRE && current_animation->name == "off") set_animation("fire");
	else if (state == OFF && current_animation->name == "fire") set_animation("off");

	if (state == FIRE) {
		if (temp_delay >= LevelManager::instance().fire_delay()) {
			state = OFF; temp_delay = 0;
		}
		else {
			temp_delay += delta_time;
		}
	}

	AnimatedActor::tick(delta_time);
}
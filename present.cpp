#include "Present.h"

void Present::tick(float delta_time) {
	if (collider) {
		if (collider->get_name().find("player") != std::string::npos ||
			collider->get_name().find("brick") != std::string::npos) {
			disable_movement();
			disable_gravity();
			collision_type = OVERLAP;
		}
	}

	ShadowActor::tick(delta_time);
}
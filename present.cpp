#include "Present.h"
#include "Thief.h"

void Present::tick(float delta_time) {
	if (y >= 368) {
		y = SCREEN_HEIGHT - 100;
		std::cout << "[DEBUG] Present fell off the window! " << this << std::endl;
		return;
	}

	Thief* thief = static_cast<Thief*>(collider);
	if (thief) {
		ShadowActor::tick(delta_time);
		return;
	}

	if (collider) {
		if (player_collision() ||
			collider->get_name().find("brick") != std::string::npos) {
			disable_movement();
			disable_gravity();
		}
	}

	ShadowActor::tick(delta_time);
}

bool Present::player_collision() {
	if (!collider) return false;
	Player* player = static_cast<Player*>(collider);
	if (!player) return false;
	if (player->has_present()) return false;

	return true;
}
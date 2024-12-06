#include<string>
#include<allegro5/allegro5.h>

#include "ShadowActor.h"

void ShadowActor::tick(float delta_time) {
	if (shadow) {
		x = shadow->get_x();
		y = shadow->get_y() - 0.01f - sprite->height;
	}

	if (frozen && freeze_time <= 0) {
		frozen = false;
		freeze_time = -1.0f;
	}

	if (frozen) {
		freeze_time -= delta_time;
		return;
	}

	AnimatedActor::tick(delta_time);
}

void ShadowActor::set_shadow_position(int _x, int _y, BaseActor* actor) {
	if (actor != shadow) return;
	x = _x;
	y = _y - 5;
	freeze(.25f);
	enable_gravity();
	enable_movement();
}
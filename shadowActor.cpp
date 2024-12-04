#include<string>

#include "ShadowActor.h"

void ShadowActor::tick(float delta_time) {
	if (shadow) {
		x = shadow->get_x();
		y = shadow->get_y() - 0.01f - sprite->height;
	}

	AnimatedActor::tick(delta_time);
}
#include <cmath>

#include "CollisionSystem.h"
#include "BaseActor.h"

void CollisionSystem::update() {

	for (size_t i = 0; i < actors.size(); i++) {
		if (!actors.at(i)) continue;

		bool collision = false;

		bool cdown = false;
		bool cright = false;
		bool cleft = false;

		for (size_t j = 0; j < actors.size(); j++) {
			if (!actors.at(j)) continue;
			//if (actors.at(i)->get_name() == "player" && actors.at(j)->get_name() == "thief") continue;

			if (actors.at(i) != actors.at(j)) {
				BaseActor* actor_1 = actors.at(i);
				BaseActor* actor_2 = actors.at(j);

				float actor_1_ceil = actor_1->get_y();
				float actor_1_floor = actor_1->get_y() + actor_1->get_height();

				float actor_2_ceil = actor_2->get_y();
				float actor_2_floor = actor_2->get_y() + actor_2->get_height();

				float actor_1_left = actor_1->get_x();
				float actor_1_right = actor_1->get_x() + actor_1->get_width();

				float actor_2_left = actor_2->get_x();
				float actor_2_right = actor_2->get_x() + actor_2->get_width();

				float actor_x_margin = (actor_1->get_width() / 2);

				//Si coninciden en X, buscamos colisión abajo (y)
				if ((actor_1_right > actor_2_left && actor_1_left < actor_2_right)) {
					if ((actor_1_floor > actor_2_ceil && std::abs(actor_1_floor - actor_2_ceil) < MAX_STEP)
						|| (actor_1_floor < actor_2_ceil && std::abs(actor_1_floor - actor_2_ceil) < MIN_STEP)) {
						if (actor_2->get_collision() == BLOCK) {
							actor_1->set_collision(DOWN, actor_2->get_y() - (actor_2->get_height() / 2) + 0.01);
							cdown = true;
						}

						actor_1->set_collider(actor_2);
						collision = true;
					}
				}

				//Si hay coincidencia en Y
				if ((actor_1_floor - MAX_STEP > actor_2_ceil) && (actor_1_ceil < actor_2_floor)) {

					//Buscamos colisión en RIGHT
					if (actor_1_right + 1 > actor_2_left && actor_1_right < actor_2_right) {
						if (actor_2->get_collision() == BLOCK) {
							actor_1->set_collision(RIGHT);
							cright = true;
						}

						actor_1->set_collider(actor_2);
						collision = true;
					}

					//Buscamos colisión en LEFT
					if (actor_1_left > actor_2_left && actor_1_left - 1 < actor_2_right) {
						if (actor_2->get_collision() == BLOCK) {
							actor_1->set_collision(LEFT);
							cleft = true;
						}

						actor_1->set_collider(actor_2);
						collision = true;
					}
				}


			}
		}

		if (!collision) actors.at(i)->set_collider(nullptr);
		if (!cright) actors.at(i)->disable_collision(RIGHT);
		if (!cleft) actors.at(i)->disable_collision(LEFT);
		if (!cdown) actors.at(i)->disable_collision(DOWN);
	}
}
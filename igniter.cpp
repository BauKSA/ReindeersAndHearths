#include "Igniter.h"
#include "Hearth.h"
#include "MemoryManager.h"
#include "Garbage.h"

void Igniter::tick(float delta_time) {
	if (direction == RIGHT && !mright) {
		set_movement(RIGHT);
		mleft = false;
	}
	else if (direction == LEFT && !mleft) {
		set_movement(LEFT);
		mright = false;
	}
	else if (direction == DOWN) {
		set_movement(DOWN);
	}

	if (collider) check_hearth();
	Enemy::tick(delta_time);
}

void Igniter::check_hearth() {
	Hearth* hearth = dynamic_cast<Hearth*>(collider);
	if (!hearth) return;

	if (y >= hearth->get_y() + hearth->get_height() - 10) {
		hearth->fire();
		Garbage::instance().move_to_bin(this);
	}
	else if (!mdown) {
		float margin = 2.0f;

		float _x = x + sprite->width / static_cast<float>(2);
		if (_x > collider->get_x() + collider->get_width() / 2 - margin &&
			_x < collider->get_x() + collider->get_width() / 2 + margin) {
			direction = DOWN;
			mright = false;
			mleft = false;
		}

	}
}
#include "Player.h"
#include "ShadowActor.h"
#include "Garbage.h"
#include "GlobalSystem.h"
#include "Hearth.h"
#include "Observer.h"
#include "Igniter.h"

void Player::tick(float delta_time) {
	if (frozen && freeze_time <= 0) {
		frozen = false;
		freeze_time = -1.0f;
		correct_animation();
	}

	if (frozen) {
		freeze_time -= delta_time;
		AnimatedActor::update(delta_time);
		return;
	}

	if (x >= 600 || y >= 400 || x < -1 || y <= 0) {
		x = 25;
		y = SCREEN_HEIGHT - 55;
	}

	check_present();
	check_igniter();
	AnimatedActor::tick(delta_time);
}

void Player::climb() {
	if (!collider) return;

	float margin = 8.0f;

	Hearth* hearth = dynamic_cast<Hearth*>(collider);
	if (!hearth) return;

	if (hearth->get_name() == "hearth-1") {
		float _x = x + sprite->width / static_cast<float>(2);
		if (_x > hearth->get_x() + hearth->get_width() / 2 - margin &&
			_x < hearth->get_x() + hearth->get_width() / 2 + margin) {
			y = SCREEN_HEIGHT - 172 - sprite->height;

			if (hearth->get_state() == FIRE) {
				set_animation("burn");
				freeze(1.5f);
				lives--;
			}
		}

	}
	else if (hearth->get_name() == "hearth-2") {
		float _x = x + sprite->width / static_cast<float>(2);
		if (_x > hearth->get_x() + hearth->get_width() / 2 - margin &&
			_x < hearth->get_x() + hearth->get_width() / 2 + margin) {
			y = 82 - sprite->height;

			if (hearth->get_state() == FIRE) {
				set_animation("burn");
				freeze(1.5f);
				lives--;
				
				if (present) {
					present = false;
					Garbage::instance().move_to_bin(present_ptr);
					present_ptr = nullptr;
					GlobalSystem::lose_present();
				}
			}
		}
	}
}

void Player::down() {
	if (!collider) return;

	Hearth* hearth = dynamic_cast<Hearth*>(collider);
	if (!hearth) return;

	float margin = 8.0f;

	if (collider->get_name() == "head-1") {
		float _x = x + sprite->width / static_cast<float>(2);
		if (_x > collider->get_x() + collider->get_width() / 2 - margin &&
			_x < collider->get_x() + collider->get_width() / 2 + margin) {
			y = SCREEN_HEIGHT - 32 - sprite->height - .1f;

			if (hearth->get_state() == FIRE) {
				set_animation("burn");
				freeze(1.5f);
				lives--;
			}
		}
	}
	else if (collider->get_name() == "head-2") {
		float _x = x + sprite->width / static_cast<float>(2);
		if (_x > collider->get_x() + collider->get_width() / 2 - margin &&
			_x < collider->get_x() + collider->get_width() / 2 + margin) {
			y = SCREEN_HEIGHT - 176 - sprite->height;

			if (hearth->get_state() == FIRE) {
				set_animation("burn");
				freeze(1.5f);
				lives--;
			}
		}
	}
}

void Player::set_collider(BaseActor* actor) {
	BaseActor::set_collider(actor);
	if (!collider) return;
	check_present();
	check_igniter();
	if (collider->get_name() == "tree") dispatch_present();
}

void Player::check_present() {
	if (!collider) return;
	if (present) return;

	ShadowActor* _shadow = dynamic_cast<ShadowActor*>(collider);
	if (_shadow) {
		_shadow->set_shadow(this);
		present = true;
		correct_animation();
		set_present(_shadow);
	}
}

void Player::correct_animation() {
	std::string an = current_animation->name;
	if (an == "walk-right" && present) set_animation("walk-right-present");
	else if (an == "walk-left" && present) set_animation("walk-left-present");
	else if (an == "burn") {
		if (mright) set_animation("walk-right");
		else if (mleft)set_animation("walk-left");
		else set_animation("stand-right");
	}
}

void Player::dispatch_present() {
	if (!present) return;
	present = false;

	if (!present_ptr) return;

	Garbage::instance().move_to_bin(present_ptr);
	present_ptr = nullptr;
	GlobalSystem::sum_points(1);
	Observer::instance().delete_present();
}

void Player::check_igniter() {
	if (!collider) return;

	Igniter* igniter = dynamic_cast<Igniter*>(collider);
	if (igniter) {
		igniter->set_collider(nullptr);
		Garbage::instance().move_to_bin(igniter);
		set_animation("burn");
		freeze(1.5f);
		lives--;
	}
}
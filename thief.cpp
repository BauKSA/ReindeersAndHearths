#include "Thief.h"
#include "Garbage.h"
#include "GlobalSystem.h"
#include "Observer.h"

void Thief::tick(float delta_time) {
	if (x <= 0 || x >= 400 - 16) {
		Garbage::instance().move_to_bin(this);
		if (collider) collider->set_collider(nullptr);
		if (actual_present != nullptr) {
			Observer::instance().delete_present();
			Garbage::instance().move_to_bin(actual_present);
			GlobalSystem::lose_present();
		}
	}



	check_player();
	check_collision();

	if (direction == RIGHT && !mright) {
		set_movement(RIGHT);
		set_animation("right");
		mleft = false;
	}
	else if (direction == LEFT && !mleft) {
		set_movement(LEFT);
		set_animation("left");
		mright = false;
	}

	temp_x = x;
	Enemy::tick(delta_time);
}

void Thief::check_collision() {
	if (!collider) return;

	ShadowActor* _shadow = dynamic_cast<ShadowActor*>(collider);
	if (_shadow && !present) {
		if (_shadow->get_shadow()) return;
		_shadow->set_shadow(this);
		present = true;
		actual_present = _shadow;
	}
}

void Thief::check_player() {
	if (!collider) return;
	Player* player = dynamic_cast<Player*>(collider);
	if (!player) return;

	if (player->has_present()) {
		throw_present();
		return;
	}



	if (present) {
		ShadowActor* p = dynamic_cast<ShadowActor*>(actual_present);
		if (p) {
			p->set_shadow(collider);
			player->set_present(p);
			present = false;
			actual_present = nullptr;
		}
	}
}

void Thief::set_collider(BaseActor* actor) {
	BaseActor::set_collider(actor);
	if (!collider) return;

	check_player();
}

void Thief::throw_present() {
	ShadowActor* p = dynamic_cast<ShadowActor*>(actual_present);
	if (!p) return;

	p->set_shadow_position(p->get_x(), p->get_y(), this);
	if(p->get_shadow() == this) p->set_shadow(nullptr);
	actual_present = nullptr;
	present = false;
}
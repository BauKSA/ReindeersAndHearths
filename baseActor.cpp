#include<iostream>
#include<cmath>

#include "BaseActor.h"

void BaseActor::add_system(GenericSystem* system) {
	if (!system) return;
	systems.push_back(system);
}

void BaseActor::add_component(GenericComponent* component) {
	if (!component) return;
	components.push_back(component);
}

void BaseActor::move(directions dir) {
	if (!has_movement) return;

	const float speed = vspeed > MAX_STEP ? MAX_STEP : vspeed;
	switch (dir) {
	case UP:
		y -= std::abs(speed);
		break;
	case DOWN:
		y += std::abs(speed);
		break;
	case RIGHT:
		if (x + hspeed > 400 - get_width() && limits) break;
		x += std::abs(hspeed);
		break;
	case LEFT:
		if (x - hspeed < 0 && limits) break;
		x -= std::abs(hspeed);
		break;
	default:
		std::cerr << "Error moving actor " << name;
		return;
	}
}

void BaseActor::set_movement(directions dir, bool key_pressed) {
	switch (dir) {
	case RIGHT:
		mright = key_pressed;
		break;
	case LEFT:
		mleft = key_pressed;
		break;
	case UP:
		mup = key_pressed;
		break;
	case DOWN:
		mdown = key_pressed;
		break;
	default:
		std::cerr << "Error moving actor " << name;
		return;
	}
}

void BaseActor::tick(float delta_time) {
	for (size_t i = 0; i < systems.size(); i++) {
		systems.at(i)->update();
	}

	for (size_t i = 0; i < components.size(); i++) {
		if (!this) return;
		components.at(i)->tick(delta_time, *this);
	}

	if (mup && !mdown) {
		move(UP);
	}

	if (mdown && !mup && !cdown) {
		move(DOWN);
	}

	if (mright && !mleft && !cright) {
		move(RIGHT);
	}

	if (mleft && !mright && !cleft) {
		move(LEFT);
	}
}

void BaseActor::jump() {
	if (jumping) return;
	y += 0.01;
	set_vspeed(JUMP);
	cdown = false;
	jumping = true;
	disable_gravity();
}

void BaseActor::disable_collision(int dir) {
	switch (dir) {
	case DOWN:
		cdown = false;
		if (!jumping) enable_gravity();
		break;
	case RIGHT:
		cright = false;
		break;
	case LEFT:
		cleft = false;
		break;
	default:
		std::cerr << "Error colliding actor " << name;
		return;
	}
}

void BaseActor::set_collision(int dir, float pos) {
	switch (dir) {
	case DOWN:
		if (cdown) break;
		cdown = true;
		jumping = false;
		disable_gravity();
		if(has_movement) y = pos;
		break;
	case RIGHT:
		if (cright) break;
		cright = true;
		break;
	case LEFT:
		if (cleft) break;
		cleft = true;
		break;
	default:
		std::cerr << "Error colliding actor " << name;
		return;
	}
}
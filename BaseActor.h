#include<string>
#include<iostream>
#include<vector>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

#include "SpriteActor.h"
#include "GenericSystem.h"
#include "GenericComponent.h"
#include "Utils.h"

#ifndef _BASEACTOR_
#define _BASEACTOR_

enum CollisionType {
	BLOCK = 0,
	OVERLAP = 1,
	IGNORE = 2
};

class BaseActor : public SpriteActor {
protected:
	//speed
	float hspeed;
	float vspeed;

	//movement
	bool has_movement;
	bool mup;
	bool mdown;
	bool mright;
	bool mleft;
	bool gravity;
	bool jumping;
	bool limits;

	//collision
	bool cdown;
	bool cright;
	bool cleft;
	CollisionType collision_type;

	BaseActor* collider;

	std::vector<GenericSystem*> systems;
	std::vector<GenericComponent*> components;
public:
	BaseActor(std::string name, float x, float y, CollisionType collision = BLOCK, float speed = 0) :
		SpriteActor(name, x, y), hspeed(speed), vspeed(0),
		mup(false), mdown(false), mright(false), mleft(false), has_movement(true), limits(true),
		cdown(false), cright(false), cleft(false), collider(nullptr), collision_type(collision),
		gravity(true), jumping(false) {
		systems = {};
		components = {};
	};

	void initialize(std::string path) { SpriteActor::initialize_sprite(path); }

	//Methods
	void set_movement(directions dir, bool key_pressed = true);
	void move(directions dir);
	void jump();

	void add_system(GenericSystem* system);
	void add_component(GenericComponent* component);

	void set_collision(int dir, float pos = 0);
	void disable_collision(int dir);

	//Virtuals
	virtual void tick(float delta_time);

	//Declared
	//Move
	void disable_movement() { has_movement = false; };
	void disable_limits() { limits = false; };

	//Speed
	void reset_vspeed() { vspeed = 0; };
	void set_vspeed(float speed) { vspeed = speed; };

	float get_vspeed()const { return vspeed; };
	float get_hspeed()const { return hspeed; };

	//Gravity
	void enable_gravity() { gravity = true; jumping = true; };
	void disable_gravity() { gravity = false; };
	bool get_gravity()const { return gravity; };

	//Collision
	bool get_cdown()const { return cdown; };
	virtual void set_collider(BaseActor* actor) { collider = actor ? actor : nullptr; };
	CollisionType get_collision()const { return collision_type; };

	virtual ~BaseActor() {
		for (GenericSystem* system : systems) {
			delete system;
		}

		for (GenericComponent* component : components) {
			delete component;
		}
	}
};

#endif // !_BASEACTOR_
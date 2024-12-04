#pragma once
#include<vector>

#include "CollisionSystem.h"
#include "GenericComponent.h"
#include "TickSystem.h"
#include "BaseActor.h"

#ifndef _OBSERVER_
#define _OBSERVER_

class Observer {
protected:
	std::vector<BaseActor*> actors;
	CollisionSystem* collision;
	TickSystem* tick;
	int presents;
public:
	Observer() :
		collision(nullptr), tick(nullptr), presents(0) {
	};

	static Observer& instance() {
		static Observer observer;
		return observer;
	}

	void configure(CollisionSystem* c, TickSystem* t) { collision = c; tick = t; };
	void add_actor_collision(BaseActor* actor) { collision->add_actor(actor); }
	void add_actor_tick(BaseActor* actor) { tick->add_actor(actor); }
	void add_actor_component(BaseActor& actor, GenericComponent& component) { actor.add_component(&component); };
	void sum_present() { presents++; };
	void delete_present() { presents--; };
	int get_presents()const { return presents; };
};

#endif // !_OBSERVER_

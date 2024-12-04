#include "MoveCommands.h"

void MoveRightCommand::execute(Player& actor) {
	actor.set_movement(RIGHT);
	if (actor.is_frozen()) return;
	if (actor.has_present()) actor.set_animation("walk-right-present");
	else actor.set_animation("walk-right");
}

void MoveLeftCommand::execute(Player& actor) {
	actor.set_movement(LEFT);
	if (actor.is_frozen()) return;
	if (actor.has_present()) actor.set_animation("walk-left-present");
	else actor.set_animation("walk-left");
}

void StandRightCommand::execute(Player& actor) {
	actor.set_movement(RIGHT, false);
	if (actor.is_frozen()) return;
	if (actor.has_present()) actor.set_animation("stand-right-present");
	else actor.set_animation("stand-right");
}

void StandLeftCommand::execute(Player& actor) {
	actor.set_movement(LEFT, false);
	if (actor.is_frozen()) return;
	if (actor.has_present()) actor.set_animation("stand-left-present");
	else actor.set_animation("stand-left");
}

void JumpCommand::execute(Player& actor) {
	actor.jump();
}

void Climb::execute(Player& actor) {
	actor.climb();
}

void Down::execute(Player& actor) {
	actor.down();
}
#pragma once
#include "BaseActor.h"
#include "AnimatedActor.h"
#include "Player.h"

#ifndef _GENERICCOMMAND_
#define _GENERICCOMMAND_

class GenericCommand {
public:
	virtual void execute() {};
	virtual void execute(Player& actor) {};
	virtual void execute(bool& running) {};
};

#endif // !_GENERICCOMMAND_

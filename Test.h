#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<allegro5/allegro.h>

#include "AnimatedActor.h"
#include "InputSystem.h"
#include "InputDriver.h"
#include "MoveCommands.h"
#include "CloseCommand.h"
#include "Player.h"
#include "Present.h"
#include "SpriteActor.h"
#include "Hearth.h"
#include "Reindeer.h"

#ifndef _TEST_
#define _TEST_

Player* initialize_test();
std::vector<BaseActor*> initialize_bricks();
BaseActor* initialize_tree();
std::vector<Hearth*> initialize_hearths();
InputSystem* initialize_input();
Present* initialize_shadow();
SpriteActor* initialize_title();
Reindeer* initialize_reindeer();

#endif // !_TEST_
#include "Test.h"
#include "JoystickMapping.h"

std::vector<BaseActor*> initialize_bricks() {
	std::vector<BaseActor*> bricks{};
	int pos_x = 0;

	for (size_t i = 0; i < 13; i++) {
		if (i == 6) {
			std::string name = "brick-" + std::to_string(i);
			BaseActor* brick = new BaseActor(name, pos_x, SCREEN_HEIGHT - 32);
			brick->initialize_sprite("./sprites/middle-brick.png");
			bricks.push_back(brick);
			brick->disable_movement();
			pos_x += brick->get_width();
		}
		else {
			std::string name = "brick-" + std::to_string(i);
			BaseActor* brick = new BaseActor(name, pos_x, SCREEN_HEIGHT - 32);
			brick->initialize_sprite("./sprites/brick.png");
			bricks.push_back(brick);
			brick->disable_movement();
			pos_x += brick->get_width();
		}
	}

	pos_x = 0;
	for (size_t i = 0; i < 13; i++) {
		if (i == 3) {
			std::string name = "brick-b-" + std::to_string(i);
			BaseActor* brick = new BaseActor(name, pos_x, 226);
			brick->initialize_sprite("./sprites/right-brick-border.png");
			bricks.push_back(brick);
			brick->disable_movement();
			pos_x += brick->get_width() + 24 + 16;
		}
		else if (i == 4) {
			std::string name = "brick-b-" + std::to_string(i);
			BaseActor* brick = new BaseActor(name, pos_x, 226);
			brick->initialize_sprite("./sprites/left-brick-border.png");
			bricks.push_back(brick);
			brick->disable_movement();
			pos_x += brick->get_width();
		}
		else {
			std::string name = "brick-b-" + std::to_string(i);
			BaseActor* brick = new BaseActor(name, pos_x, 226);
			brick->initialize_sprite("./sprites/brick.png");
			bricks.push_back(brick);
			brick->disable_movement();
			pos_x += brick->get_width();
		}
	}

	pos_x = 0;
	for (size_t i = 0; i < 13; i++) {
		if (i == 8) {
			std::string name = "brick-b-" + std::to_string(i);
			BaseActor* brick = new BaseActor(name, pos_x, 84);
			brick->initialize_sprite("./sprites/right-brick-border.png");
			bricks.push_back(brick);
			brick->disable_movement();
			pos_x += brick->get_width() + 24 + 16;
		}
		else if (i == 9) {
			std::string name = "brick-b-" + std::to_string(i);
			BaseActor* brick = new BaseActor(name, pos_x, 84);
			brick->initialize_sprite("./sprites/left-brick-border.png");
			bricks.push_back(brick);
			brick->disable_movement();
			pos_x += brick->get_width();
		}
		else {
			std::string name = "brick-b-" + std::to_string(i);
			BaseActor* brick = new BaseActor(name, pos_x, 84);
			brick->initialize_sprite("./sprites/brick.png");
			bricks.push_back(brick);
			brick->disable_movement();
			pos_x += brick->get_width();
		}
	}

	return bricks;
}

BaseActor* initialize_tree() {
	BaseActor* tree = new BaseActor("tree", 326, 10, OVERLAP);
	tree->initialize_sprite("./sprites/tree.png");

	return tree;
}

Player* initialize_test() {
	AnimationPaths walk_right;
	walk_right.name = "walk-right";
	walk_right.paths = {
		"./sprites/pj/stand-right.png",
		"./sprites/pj/walk-right.png"
	};

	AnimationPaths walk_right_present;
	walk_right_present.name = "walk-right-present";
	walk_right_present.paths = {
		"./sprites/pj/stand-right-present.png",
		"./sprites/pj/walk-right-present.png"
	};

	AnimationPaths walk_left;
	walk_left.name = "walk-left";
	walk_left.paths = {
		"./sprites/pj/stand-left.png",
		"./sprites/pj/walk-left.png",
	};

	AnimationPaths walk_left_present;
	walk_left_present.name = "walk-left-present";
	walk_left_present.paths = {
		"./sprites/pj/stand-left-present.png",
		"./sprites/pj/walk-left-present.png"
	};

	AnimationPaths stand_right;
	stand_right.name = "stand-right";
	stand_right.paths = {
		"./sprites/pj/stand-right.png",
	};

	AnimationPaths stand_right_present;
	stand_right_present.name = "stand-right-present";
	stand_right_present.paths = {
		"./sprites/pj/stand-right-present.png"
	};

	AnimationPaths stand_left;
	stand_left.name = "stand-left";
	stand_left.paths = {
		"./sprites/pj/stand-left.png",
	};

	AnimationPaths stand_left_present;
	stand_left_present.name = "stand-left-present";
	stand_left_present.paths = {
		"./sprites/pj/stand-left-present.png"
	};

	AnimationPaths burn;
	burn.name = "burn";
	burn.paths = {
		"./sprites/pj/burn-a.png",
		"./sprites/pj/burn-b.png"
	};

	Player* actor = new Player("player", 50, FIRST_FLOOR - 16, 2.5);
	actor->initialize({
		stand_right,
		stand_left,
		walk_right,
		walk_left,
		stand_right_present,
		stand_left_present,
		walk_right_present,
		walk_left_present,
		burn
		});

	return actor;
}

std::vector<Hearth*> initialize_hearths() {
	AnimationPaths fire;
	fire.name = "fire";
	fire.paths = {
		"./sprites/hearth/fire-1.png",
		"./sprites/hearth/fire-2.png"
	};

	AnimationPaths off;
	off.name = "off";
	off.paths = {
		"./sprites/hearth/extinct.png"
	};

	AnimationPaths _head;
	_head.name = "default";
	_head.paths = {
		"./sprites/hearth/head.png"
	};

	Hearth* hearth_1 = new Hearth("hearth-1", 400 - 48, SCREEN_HEIGHT - 32 - 110, 0, OVERLAP);
	hearth_1->initialize({ fire, off });
	hearth_1->disable_movement();

	Hearth* hearth_2 = new Hearth("hearth-2", 0, 226 - 110, 0, OVERLAP);
	hearth_2->initialize({ fire, off });
	hearth_2->disable_movement();

	Hearth* head_1 = new Hearth("head-1", 400 - 48, SCREEN_HEIGHT - 32 - 110 - 32 - 5, 0, OVERLAP);
	head_1->initialize({ _head });
	head_1->disable_movement();
	hearth_1->set_head(head_1);

	Hearth* head_2 = new Hearth("head-2", 0, 226 - 110 - 32 - 5, 0, OVERLAP);
	head_2->initialize({ _head });
	head_2->disable_movement();
	hearth_2->set_head(head_2);

	return { hearth_1, hearth_2, head_1, head_2 };
}

InputSystem* initialize_input() {
	MoveRightCommand* move_right = new MoveRightCommand();
	MoveLeftCommand* move_left = new MoveLeftCommand();
	StandRightCommand* stand_right = new StandRightCommand();
	StandLeftCommand* stand_left = new StandLeftCommand();
	CloseCommand* _close = new CloseCommand();
	JumpCommand* _jump = new JumpCommand();
	Climb* _climb = new Climb();
	Down* _down = new Down();

	KeyCommand right(JOY_BUTTON_RIGHT, true, move_right);
	KeyCommand left(JOY_BUTTON_LEFT, true, move_left);
	KeyCommand sright(JOY_BUTTON_RIGHT, false, stand_right);
	KeyCommand sleft(JOY_BUTTON_LEFT, false, stand_left);
	KeyCommand close(JOY_BUTTON_START, true, _close);
	KeyCommand jump(JOY_BUTTON_A, true, _jump);
	KeyCommand climb(JOY_BUTTON_B, true, _climb);
	KeyCommand down(JOY_BUTTON_DOWN, true, _down);

	std::vector<KeyCommand> commands{ right, left, sright, sleft, close, jump, climb, down };

	InputDriver* driver = new InputDriver(commands);
	InputSystem* test_input = new InputSystem(driver);

	return test_input;
}

Present* initialize_shadow() {
	AnimationPaths _default;
	_default.name = "default";
	_default.paths = {
		"./sprites/presents/present-b.png"
	};

	Present* shadow = new Present("present", 225, FIRST_FLOOR - 100, 0);
	shadow->initialize({ _default });

	return shadow;
}

SpriteActor* initialize_title() {
	SpriteActor* title = new SpriteActor("title", 400, 0);
	title->initialize_sprite("./sprites/title.png");

	return title;
}

Reindeer* initialize_reindeer() {
	AnimationPaths right;
	right.name = "right";
	right.paths = {
		"./sprites/reindeer/stand-right.png",
		"./sprites/reindeer/walk-right.png",
		"./sprites/reindeer/stand-right-closed.png",
		"./sprites/reindeer/walk-right.png",
		"./sprites/reindeer/stand-right.png",
		"./sprites/reindeer/walk-right.png"
	};

	AnimationPaths left;
	left.name = "left";
	left.paths = {
		"./sprites/reindeer/stand-left.png",
		"./sprites/reindeer/walk-left.png",
		"./sprites/reindeer/stand-left-closed.png",
		"./sprites/reindeer/walk-left.png",
		"./sprites/reindeer/stand-left.png",
		"./sprites/reindeer/walk-left.png"
	};

	Reindeer* reindeer = new Reindeer("reindeer", 300, SCREEN_HEIGHT - 140, 1.25, OVERLAP);
	reindeer->initialize({ right, left });
	reindeer->disable_limits();

	return reindeer;
}
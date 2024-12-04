#pragma once
#include<vector>
#include<string>
#include<chrono>
#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>

#ifndef _UTILS_
#define _UTILS_

constexpr float SCREEN_WIDTH = 600;
constexpr float SCREEN_HEIGHT = 400;

constexpr float WORLD_WIDTH = 600;
constexpr float WORLD_HEIGHT = 400;

constexpr float FRAME_RATE = .15;

constexpr float JUMP = 3.5;
constexpr float MIN_STEP = .25;
constexpr float MAX_STEP = 8;
constexpr int FIRST_FLOOR = SCREEN_HEIGHT - 32;

enum directions {
	UP = 1,
	DOWN = 2,
	RIGHT = 3,
	LEFT = 4
};

struct Sprite {
	int width;
	int height;
	ALLEGRO_BITMAP* frame;
};

struct Animation {
	std::string name;
	int size;
	std::vector<Sprite*> frames;
};

struct AnimationPaths {
	std::string name;
	std::vector<std::string> paths;
};

float generate_random(int a = 0, int b = 1);

#endif // !_UTILS_
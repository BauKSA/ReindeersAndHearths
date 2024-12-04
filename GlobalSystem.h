#pragma once
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_image.h>

#include "Player.h"
#include "Utils.h"

#ifndef _GLOBALSYSTEM_
#define _GLOBALSYSTEM_

class GlobalSystem {
protected:
	ALLEGRO_FONT* font;
	ALLEGRO_BITMAP* heart;
	Player* player;
public:
	GlobalSystem(Player* _player) : player(_player) {
		font = al_load_ttf_font("./fonts/PixelOperator.ttf", 15, 0);
		heart = al_load_bitmap("./sprites/heart.png");
	};

	static int points;
	static void sum_points(int p) { GlobalSystem::points += p; }

	void draw() const {
		for (size_t i = 0; i < player->get_lives(); i++) {
			int x = 445;
			al_draw_bitmap(heart, x + i * 21, 130, 0);
		}
		al_draw_textf(font, al_map_rgb(255, 255, 255), 445, 150, 0, "Points: %d", GlobalSystem::points);
	}
};

#endif // !_GLOBALSYSTEM_

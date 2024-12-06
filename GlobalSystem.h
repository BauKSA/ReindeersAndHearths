#pragma once
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_image.h>

#include "Player.h"
#include "Utils.h"
#include "LevelManager.h"

#ifndef _GLOBALSYSTEM_
#define _GLOBALSYSTEM_

class GlobalSystem {
protected:
	ALLEGRO_FONT* font;
	ALLEGRO_BITMAP* heart;
	ALLEGRO_BITMAP* present;
	ALLEGRO_BITMAP* present_lost;
	ALLEGRO_BITMAP* level_icon;
	Player* player;
public:
	GlobalSystem(Player* _player) : player(_player) {
		font = al_load_ttf_font("./fonts/PixelOperator.ttf", 16, 0);
		heart = al_load_bitmap("./sprites/heart.png");
		present = al_load_bitmap("./sprites/presents/present-icon.png");
		present_lost = al_load_bitmap("./sprites/presents/present-icon-error.png");
		level_icon = al_load_bitmap("./sprites/level-icon.png");
	};

	static int lost;
	static int points;

	static void lose_present() { GlobalSystem::lost++; }
	static void sum_points(int p) {
		GlobalSystem::points += p;
		if (GlobalSystem::points % 5 == 0) LevelManager::instance().sum_level();
	}

	void draw() const {
		for (size_t i = 0; i < player->get_lives(); i++) {
			int x = 445;
			al_draw_bitmap(heart, x + i * 21, 130, 0);
		}

		int x = 443;
		al_draw_bitmap(present, x, 155, 0);
		al_draw_textf(font, al_map_rgb(255, 255, 255), x + 20, 156, 0, "%d", GlobalSystem::points);

		al_draw_bitmap(present_lost, x, 180, 0);
		al_draw_textf(font, al_map_rgb(255, 255, 255), x + 20, 181, 0, "%d", GlobalSystem::lost);

		al_draw_bitmap(level_icon, x, 205, 0);
		al_draw_textf(font, al_map_rgb(255, 255, 255), x + 20, 206, 0, "%d", LevelManager::instance().level());
	}
};

#endif // !_GLOBALSYSTEM_

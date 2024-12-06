#pragma once
#ifndef _LEVELMANAGER_
#define _LEVELMANAGER_

class LevelManager {
protected:
	float _fire_delay;
	int _present_limit;
	float _igniter_delay;
	float _thief_delay;
	int max_level;
	int _level;
public:
	LevelManager() : _fire_delay(2), _present_limit(5),
		_igniter_delay(10), max_level(9), _level(1), _thief_delay(25)
	{ }

	static LevelManager& instance() {
		static LevelManager manager;
		return manager;
	}

	float fire_delay()const { return _fire_delay; };
	int present_limit()const { return _present_limit; };
	float igniter_delay()const { return _igniter_delay; };
	float thief_delay()const { return _thief_delay; };
	int level()const { return _level; };
	void sum_level() {
		if (_level == max_level) {
			_level++;
			return;
		}

		_level++;

		_fire_delay += .33f; //TERMINA EN 5s
		_igniter_delay -= .72f; //TERMINA EN 3.5s
		_thief_delay -= 1.66f; //TERMINA EN 10s
	}
};

#endif // !_LEVELMANAGER_

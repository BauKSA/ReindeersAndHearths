#pragma once
#ifndef _LEVELMANAGER_
#define _LEVELMANAGER_

class LevelManager {
protected:
	float _fire_delay;
	int _present_limit;
	float _igniter_delay;
public:
	LevelManager() : _fire_delay(2), _present_limit(2),
		_igniter_delay(10)
	{ }

	static LevelManager& instance() {
		static LevelManager manager;
		return manager;
	}

	float fire_delay()const { return _fire_delay; };
	int present_limit()const { return _present_limit; };
	float igniter_delay()const { return _igniter_delay; };

};

#endif // !_LEVELMANAGER_

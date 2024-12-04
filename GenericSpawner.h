#pragma once
#ifndef _GENERICSPAWNER_
#define _GENERICSPAWNER_

class GenericSpawner {
protected:
	float temp_delay;
public:
	GenericSpawner() : temp_delay(0) {}

	virtual void tick(float delta_time) {};
	virtual void spawn() {};
};

#endif //!_GENERICSPAWNER_
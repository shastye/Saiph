#ifndef MOTHERSHIP_CLUBB
#define MOTHERSHIP_CLUBB

#include "Model/Ship.h"
#include "BaseCommand.h"
#include <vector>

class MotherShip : public Ship
{
private:
	std::vector<Ship*> shadows;
	std::vector<BaseCommand*> commands;

	void process_commands(float _delta);
	void cleanup();

public:
	MotherShip(const Ship& _ship);
	~MotherShip();

	void add_shadow(Ship* _shadow);

	void Heartbeat(float _delta);
};

#endif
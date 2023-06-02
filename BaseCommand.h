#ifndef BASECOMMAND_CLUBB
#define BASECOMMAND_CLUBB

#include "Model/Ship.h"

class BaseCommand
{
protected:
	Ship* target;

private:
	float delay;

public:
	BaseCommand();
	BaseCommand(Ship* _target, float _delay);

	void set_target(Ship* _target);
	Ship* get_target() const;

	void set_delay(float _delay);
	float get_delay() const;

	virtual void Execute() = 0;
};

#endif
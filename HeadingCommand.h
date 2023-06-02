#ifndef HEADINGCOMMAND_CLUBB
#define HEADINGCOMMAND_CLUBB

#include "BaseCommand.h"

class HeadingCommand : public BaseCommand
{
private: 
	float heading;

public:
	HeadingCommand();
	HeadingCommand(float _heading, Ship* _target, float _delay);

	void set_heading(float _heading);
	float get_heading() const;

	void Execute();
};

#endif
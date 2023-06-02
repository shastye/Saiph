#ifndef VELOCITYCOMMAND_CLUBB
#define VELOCITYCOMMAND_CLUBB

#include "BaseCommand.h"

class VelocityCommand : public BaseCommand
{
private:
	Vec2f velocity;

public:
	VelocityCommand();
	VelocityCommand(Vec2f _velocity, Ship* _target, float _delay);
	VelocityCommand(float _velX, float _velY, Ship* _target, float _delay);

	void set_velocity(Vec2f _velocity);
	Vec2f get_velocity() const;

	void set_velocityY(float _velY);
	float get_velocityY() const;

	void set_velocityX(float _velX);
	float get_velocityX() const;

	void Execute();
};

#endif
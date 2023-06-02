#include "precompiled_header"
#include "VelocityCommand.h"

VelocityCommand::VelocityCommand() {
	velocity = Vec2f(0.0f, 0.0f);
}
VelocityCommand::VelocityCommand(Vec2f _velocity, Ship* _target, float _delay) : BaseCommand(_target, _delay) {
	velocity = _velocity;
}
VelocityCommand::VelocityCommand(float _velX, float _velY, Ship* _target, float _delay) : BaseCommand(_target, _delay) {
	velocity = Vec2f(_velX, _velY);
}


void VelocityCommand::set_velocity(Vec2f _velocity) {
	velocity = _velocity;
}
Vec2f VelocityCommand::get_velocity() const {
	return velocity;
}

void VelocityCommand::set_velocityY(float _velY) {
	velocity.y = _velY;
}
float VelocityCommand::get_velocityY() const {
	return velocity.y;
}

void VelocityCommand::set_velocityX(float _velX) {
	velocity.x = _velX;
}
float VelocityCommand::get_velocityX() const {
	return velocity.x;
}


void VelocityCommand::Execute() {
	target->SetVelocity(velocity);
}
#include "precompiled_header"
#include "BaseCommand.h"

BaseCommand::BaseCommand(){
	target = nullptr;
	delay = 0.0f;
}
BaseCommand::BaseCommand(Ship* _target, float _delay){
	target = _target;
	delay = _delay;
}


void BaseCommand::set_target(Ship* _target) {
	target = _target;
}
Ship* BaseCommand::get_target() const {
	return target;
}

void BaseCommand::set_delay(float _delay) {
	delay = _delay;
}
float BaseCommand::get_delay() const {
	return delay;
}
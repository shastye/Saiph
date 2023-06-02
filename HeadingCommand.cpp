#include "precompiled_header"
#include "HeadingCommand.h"

HeadingCommand::HeadingCommand() {
	heading = 0.0f;
}
HeadingCommand::HeadingCommand(float _heading, Ship* _target, float _delay) : BaseCommand(_target, _delay) {
	heading = _heading;
}


void HeadingCommand::set_heading(float _heading) {
	heading = _heading;
}
float HeadingCommand::get_heading() const {
	return heading;
}



void HeadingCommand::Execute() {
	target->SetHeading(heading);
}
#include "precompiled_header"
#include "MotherShip.h"
#include "View/ViewManager.h"
#include "VelocityCommand.h"
#include "HeadingCommand.h"


void MotherShip::process_commands(float _delta) {
	for (auto iter = commands.begin(); iter != commands.end(); iter++) {
		if ((*iter)->get_delay() > 0) {
			(*iter)->set_delay((*iter)->get_delay() - _delta);
		}
		else { // if ((*iter)->get_delay() <= 0
			(*iter)->Execute();
			delete *iter;
			iter = commands.erase(iter);
		}

		if (iter == commands.end()) {
			break;
		}
	}
}
void MotherShip::cleanup() {
	for (int i = 0; i < (int)commands.size(); i++)
	{
		delete commands[i];
		commands.erase(commands.begin() + i);
	}

	for (int i = 0; i < (int)shadows.size(); i++) {
		shadows[i]->SetVelocity(0.0f, 0.0f);
		shadows[i]->SetPosition(this->GetPosition());
		shadows[i]->SetHeading(this->GetHeading());
	}
}


MotherShip::MotherShip(const Ship& _ship) : Ship(_ship) {

}
MotherShip::~MotherShip() {
	for each (Ship* shadow in shadows) {
		if (shadow) {
			ViewManager::GetInstance().RemoveObject(shadow);
			delete shadow;
		}
	}

	cleanup();
}

void MotherShip::add_shadow(Ship* _shadow) {
	shadows.push_back(_shadow);
}

void MotherShip::Heartbeat(float _delta) {
	if (commands.size() != 0) {
		process_commands(_delta);
	}

	Ship::Heartbeat(_delta);

	if (GetAfterburnerFlag()) {

		const float MULTIPLIER = 0.05f;
		const int SIZE = shadows.size();

		for (int i = 0; i < SIZE; i++) {
			shadows[i]->Ship::Heartbeat(_delta);

			VelocityCommand* velCom = new VelocityCommand();
			velCom->set_velocity(MotherShip::GetVelocity());
			velCom->set_delay(MULTIPLIER * (i + 1));
			velCom->set_target(shadows[i]);

			HeadingCommand* headCom = new HeadingCommand();
			headCom->set_heading(MotherShip::GetHeading());
			headCom->set_delay(MULTIPLIER * (i + 1));
			headCom->set_target(shadows[i]);

			commands.push_back(velCom);
			commands.push_back(headCom);
		}
	}
	else {
		cleanup();
	}
}


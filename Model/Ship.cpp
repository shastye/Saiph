#include "precompiled_header"
#include "../Model/Ship.h"

Ship::Ship()
{
	SetCost(-1);
	SetLastFired(0);
	SetArmor(1);
	SetShield(0);
	SetBattery(0);
	SetAfterburner(0);
	SetAfterburnerFlag(false);

	SetDeflector(nullptr);
}

Ship::~Ship()
{
}

// mutators
void Ship::SetAfterburnerFlag(bool _afterburnerFlag) { afterburnerFlag = _afterburnerFlag; }
void Ship::SetCost(int _cost) { cost = _cost; }
void Ship::SetArmor(float _armor)
{
	if (_armor > MAX_ARMOR)
		_armor = MAX_ARMOR;
	armor = _armor;
}
void Ship::SetShield(float _shield) { shield = _shield; }
void Ship::SetBattery(float _battery) { battery = _battery; }
void Ship::SetLastFired(float _time) { lastFired = _time; }
void Ship::SetAfterburner(float _energy)
{
	afterburner = _energy;
	if (afterburner < 0)
		afterburner = 0;
}
void Ship::SetDeflector(Deflector* _deflector) { deflector = _deflector; }

// accessors
bool Ship::GetAfterburnerFlag() const { return afterburnerFlag; }
int Ship::GetCost() const { return cost; }
float Ship::GetArmor() const { return armor; }
float Ship::GetShield() const { return shield; }
float Ship::GetBattery() const { return battery; }
float Ship::GetLastFired() const { return lastFired; }
float Ship::GetAfterburner() const { return afterburner; }
Deflector* Ship::GetDeflector() const { return deflector; }

// interface methods
void Ship::Heartbeat(float _delta)
{
	MovingObject::Heartbeat(_delta);

	if (deflector) {
		deflector->Heartbeat(_delta);
	}

	// bounds check
	if (GetXPosition() < 0)
		SetXPosition(0);
	if (GetXPosition() > BOUNDS_SIZE)
		SetXPosition(BOUNDS_SIZE);
	if (GetYPosition() < 0)
		SetYPosition(0);
	if (GetYPosition() > BOUNDS_SIZE)
		SetYPosition(BOUNDS_SIZE);
}
bool Ship::Collide(const BaseObject& _in) const {
	return BaseObject::Collide(_in);
}

bool Ship::Collide(Bullet& _in) const {
	if (!deflector || !deflector->Collide(_in)) {
		return BaseObject::Collide(_in);
	}
	else {	// if collides with deflector
		deflector->Deflect(&_in);
		return false;
	}
}
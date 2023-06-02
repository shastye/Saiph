//vector<Vec2f> a;
//unsigned int b = 6, c = 0;
//float e = 0, f, l;
//Vec2f g;
//MovingObject h;
//PropulsionFlyweight k;

#include "precompiled_header"
#include "MovingObject.h"
#include <vector>

std::vector<Vec2f> waypoints;
unsigned int flyweight = 6, currentWaypoint = 0;
float spazTime = 0;
Vec2f heading;
MovingObject* ship;
PropulsionFlyweight pfw;


void Behavior(float _delta)
{
	if(currentWaypoint >= waypoints.size())
		currentWaypoint = 0;
	if(spazTime < 0)
	{
		Vec2f i = heading - ship->GetPosition();
		i.Normalize();
		float tempHeading = SaiphApp::GetHeadingFromUnitVector(i);
		ship->SetHeading(tempHeading);

		Vec2f j = waypoints[currentWaypoint] - ship->GetPosition();
		float horizontalCenter = ship->GetWidth() / 2;
		if(j * j < horizontalCenter * horizontalCenter)
		{
			spazTime = 1.0f;
			currentWaypoint++;
		}
		j.Normalize();
		pfw = SaiphApp::GetPropulsionFlyweight(flyweight);
		j *= pfw.force;
		ship->SetVelocity(j);
	}
	else
	{
		spazTime -= _delta;
		ship->SetHeading(RandomFloat(0, 2 * PI).GenerateValue());
	}

	ship->Heartbeat(_delta);
}
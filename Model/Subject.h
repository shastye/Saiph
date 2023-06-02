#ifndef SUBJECT_CLUBB
#define SUBJECT_CLUBB

#include "Observer.h"
#include <list>

class Subject
{
private:
	std::list<Observer*> observers;

public:
	~Subject();

	void Attach(Observer* _obs);
	void Detach(Observer* _obs);
	void NotifyObservers(ObserverEvent _obsEvent);
};

#endif
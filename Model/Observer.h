#ifndef OBSERVER_CLUBB
#define OBSERVER_CLUBB

enum class ObserverEvent { 
	ACTIVATE , 
	SUBJECT_DEATH 
};

class Observer
{
public:
	virtual void Notification(ObserverEvent _obsEvent) = 0;
};

#endif
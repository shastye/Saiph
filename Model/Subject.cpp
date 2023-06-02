#include "precompiled_header"
#include "Subject.h"

Subject::~Subject(){
	for each (Observer * obs in observers) {
		obs->Notification(ObserverEvent::SUBJECT_DEATH);
	}

	observers.clear();
}

void Subject::Attach(Observer* _obs){
	observers.push_back(_obs);
}
void Subject::Detach(Observer* _obs){
	observers.remove(_obs);
}
void Subject::NotifyObservers(ObserverEvent _obsEvent){
	for each (Observer * obs in observers) {
		obs->Notification(_obsEvent);
	}
}
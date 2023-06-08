#include"TimeMonitor.h"

void TimeMonitor::setTime(float time){
	this->time = time;
	curT = 0;
}

void TimeMonitor::tick(float delta){
	curT += delta;
}

bool TimeMonitor::isTime() {
	return time <= curT;
}

void TimeMonitor::restart() {
	curT = 0;
}
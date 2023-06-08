#pragma once
#include"Tickable.h"
class TimeMonitor :public Tickable
{
	float time, curT;
 public:
	 void setTime(float time);
	 bool isTime();
	 void restart();
	 virtual void tick(float delta)override;
};
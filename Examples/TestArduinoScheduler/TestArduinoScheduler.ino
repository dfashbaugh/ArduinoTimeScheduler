#include "Scheduler.h"

void TestMe()
{
	Serial.println("World");
}

void TestThis()
{
	Serial.println("Hello");
}

FunctionScheduler myScheduler(3);

void setup()
{
	Serial.begin(9600);
	myScheduler.AddFunction(TestMe, 1000);
	myScheduler.AddFunction(TestThis, 500);
	millis();
}

void loop()
{
	myScheduler.RunFunctions();
}
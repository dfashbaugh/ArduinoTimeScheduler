#include "Scheduler.h"

FunctionScheduler::FunctionScheduler(int numFunctions)
{
	FuncArray = new FunctionAndTime[numFunctions];
	curMaxFunctions = 0;
}
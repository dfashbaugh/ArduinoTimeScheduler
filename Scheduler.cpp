#include "Scheduler.h"

FunctionScheduler::FunctionScheduler(int numFunctions)
{
	FuncArray = new FunctionAndTime[numFunctions];
	curMaxFunctions = 0;
	maxFunctions = numFunctions;
}

void FunctionScheduler::AddFunction(funcToRepeat function, unsigned long interval)
{
	if(curMaxFunctions < maxFunctions)
	{
		FunctionAndTime newFuncAndTime;
		newFuncAndTime.theFunction = function;
		newFuncAndTime.interval = interval;
		newFuncAndTime.lastTime = 0;

		FuncArray[curMaxFunctions] = newFuncAndTime;
		curMaxFunctions++;
	}
}

void FunctionScheduler::RunFunctions(unsigned long testTime)
{
	for(int i = 0; i < curMaxFunctions; i++)
	{
		unsigned long curTime = 0;

#ifdef ARDUINO
		curTime = millis();
#endif

		if(testTime > 0)
		{
			curTime = testTime;
		}

		if(curTime - FuncArray[i].lastTime > FuncArray[i].interval)
		{
			FuncArray[i].theFunction();
			FuncArray[i].lastTime = curTime;
		}
	}
}
#include "Scheduler.h"

FunctionScheduler::FunctionScheduler(int numFunctions)
{
	FuncArray = new FunctionAndTime[numFunctions];
	curMaxFunctions = 0;
}

void FunctionScheduler::AddFunction(funcToRepeat function, unsigned long interval)
{
	FunctionAndTime newFuncAndTime;
	newFuncAndTime.theFunction = function;
	newFuncAndTime.interval = interval;
	newFuncAndTime.lastTime = 0;

	FuncArray[curMaxFunctions] = newFuncAndTime;
	curMaxFunctions++;
}

void FunctionScheduler::RunFunctions()
{
	for(int i = 0; i < curMaxFunctions; i++)
	{
		unsigned long curTime = 0;

		if(curTime - FuncArray[i].lastTime > FuncArray[i].interval)
		{
			FuncArray[i].theFunction();
			FuncArray[i].lastTime = curTime;
		}
	}
}
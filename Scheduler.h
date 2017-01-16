#ifdef ARDUINO
#include "Arduino.h"
#endif

typedef void (*funcToRepeat)(void);

struct FunctionAndTime
{
	funcToRepeat theFunction;
	unsigned long lastTime;
	unsigned long interval;
};

class FunctionScheduler
{
public:
	FunctionScheduler(int numFunctions);
	~FunctionScheduler() {};

	void AddFunction(funcToRepeat function, unsigned long interval);
	void RunFunctions(unsigned long testTime = 0);

private:
	FunctionAndTime* FuncArray;
	int curMaxFunctions;
	int maxFunctions;
};
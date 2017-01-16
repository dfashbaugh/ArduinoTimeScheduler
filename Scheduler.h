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

private:
	FunctionAndTime* FuncArray;
	int curMaxFunctions;
};
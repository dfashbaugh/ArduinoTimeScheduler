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

private:
	FunctionAndTime* FuncArray;
	int curMaxFunctions;
};
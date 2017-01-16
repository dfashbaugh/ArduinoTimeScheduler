#include <iostream>
#include "Scheduler.h"

using namespace std;

void TestMe()
{
	cout << "TESTED" << endl;
}

FunctionScheduler myScheduler(3);

int main(void)
{
	cout << "Hello" << endl;
	myScheduler.AddFunction(TestMe, 10);

	myScheduler.RunFunctions(11);

	return 0;
}
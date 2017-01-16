#ifndef ARDUINO

#include <iostream>
#include "Scheduler.h"

using namespace std;

void TestMe()
{
	cout << "TESTED";
}

void TestThis()
{
	cout << "Test This!";
}

FunctionScheduler myScheduler(3);

int main(void)
{
	cout << "Hello" << endl;
	myScheduler.AddFunction(TestMe, 10);
	myScheduler.AddFunction(TestThis, 10);

	for(int i = 0; i < 30; i++)
	{
		cout << "Outputs At " << i << ": ";
		myScheduler.RunFunctions(i);
		cout << endl;
	}

	return 0;
}

#endif
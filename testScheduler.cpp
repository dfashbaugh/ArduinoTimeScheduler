#ifndef ARDUINO

#include <iostream>
#include "Scheduler.h"

using namespace std;

int testVal1 = 0;
int testVal2 = 0;

void testAdd1()
{
	testVal1++;
}

void testAdd2()
{
	testVal2++;
}

FunctionScheduler myScheduler(3);

int main(void)
{
	cout << "Begin Quick Test!" << endl;
	myScheduler.AddFunction(testAdd1, 5);
	myScheduler.AddFunction(testAdd2, 10);

	for(int i = 0; i < 35; i++)
	{
		myScheduler.RunFunctions(i);
		cout << "Outputs At " << i << ": " << testVal1 << " " << testVal2 << endl;
	}

	if(testVal1 == 5 && testVal2 == 3)
	{
		cout << "Test Successful" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}

	return 0;
}

#endif
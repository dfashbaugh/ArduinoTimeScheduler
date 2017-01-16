#include <iostream>
#include "Scheduler.h"

using namespace std;

void TestMe()
{
	cout << "TESTED";
}

FunctionScheduler myScheduler(3);

int main(void)
{
	cout << "Hello" << endl;
	myScheduler.AddFunction(TestMe, 10);

	for(int i = 0; i < 30; i++)
	{
		cout << "Outputs At " << i << ": ";
		myScheduler.RunFunctions(i);
		cout << endl;
	}
	

	return 0;
}
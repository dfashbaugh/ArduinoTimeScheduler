# ArduinoTimeScheduler

Very basic system to schedule tasks to run at predefined intervals on Arduino

Simply define a function, then give it an interval. The function will run every time that number of milliseconds passes.

Also, this is a basic synchronous library. These aren't based on timer interrupts. Its just a basic way to avoid delays and to cleanly do periodic things! But don't bet your life on its timing ability.

## Usage

* Include the scheduler
```
#include "Scheduler.h" // Include the scheduler!
```

* Create a function scheduler object with an argument of the number of functions we would like to schedule
```
FunctionScheduler myScheduler(3); // Create a scheduler with the number of functions defined
```

* Create your functions! They must return void and take void argument.
```
void TestMe()
{
	Serial.println("World");
}

void TestThis()
{
	Serial.println("Hello");
}
```

* Add your functions to the scheduler, and indicate an interval
```
myScheduler.AddFunction(TestMe, 1000);    // Schedule TestMe to run every second
myScheduler.AddFunction(TestThis, 500);   // Schedule TestThis to run every 500ms
```

* In your loop, always call RunFunctions
```
myScheduler.RunFunctions()
```

## Use Cases
This is great for anything that you want to do periodically, but don't want to delay for.

For Example: Reading sensors and printing things periodically

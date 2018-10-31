// jedii 10 29 18
// a program for practicing classes

#include <iostream>
#include <iomanip>
#include <string>
#include "clockType.h"

using namespace std;

int main() {
	// declare our important variables
	clockType myClock(23, 59, 1);
	clockType yourClock(20, 45, 59);

	// display myClock
	cout << "The time on myClock should be 23:59:01. Hope it works." << endl;
	myClock.print_time();

	// display yourClock
	cout << "The time on yourClock should be 20:45:59. This should work." << endl;
	yourClock.print_time();

	// compare the clocks to see if they have the same times
	if (myClock.equal_time(yourClock)) cout << "These two clock times are equal." << endl; // tell the user if they do...
	else cout << "The times are not equal." << endl; // ...or don't

	// set the time on my clock to be 17:59:59, then increment it
	cout << endl;
	myClock.set_time(17, 59, 59);
	myClock.increment_secs();

	system("pause");
	return 0;
}

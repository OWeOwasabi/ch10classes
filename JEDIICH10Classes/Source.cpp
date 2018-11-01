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
	
	// check to see if our elapsed time function is working properly
	cout << endl << "A testClock has been set to 00:01:05, and should display that there are 65 seconds in the day elapsed." << endl;
	clockType testClock(0, 1, 5); // declare our clock for testing
	cout << testClock.elapsed_time() << endl;
	// check to see if our military to 12 function is working
	cout << "Now we're going to convert our clock to 12hr format. It should show 12:01:05 am" << endl;
	testClock.military_to_12(); // call our function for converting military time to 12 hr time
	testClock.print_time(); // now print the new time
	// check to see if our 12 to military function is working
	cout << "Now convert it back to military format. It should show 00:01:05" << endl;
	testClock.twelve_to_military(); // call our function for converting 12hr to military
	testClock.print_time(); // print our new time
	// now test our remaining_time() function
	// we're going to readjust testClock for easier math
	cout << "We've set our testClock to 23:30:49, and it should show there are 1751 seconds left in the day" << endl;
	testClock.set_time(23, 30, 49);
	cout << testClock.remaining_time() << endl;

	// test the compare_time() function
	cout << "myClock is set to 22:53:39, yours is set to 20:52:38. the difference between them should be 2:01:01" << endl;
	myClock.set_time(22, 53, 39);
	yourClock.set_time(20, 52, 38);
	myClock.compare_time(yourClock);

	system("pause");
	return 0;
}

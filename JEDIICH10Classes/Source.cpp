// jedii and logan 10 29 18
// a program for enhanced classes

#include <iostream>
#include <iomanip>
#include <string>
#include "clockType.h"

using namespace std;

int main() {
	// prompt the user for what time it is
	int hrs, min, sec; // create our variables for storing user input
	cout << "Hey, what time is it in military format?" << endl;
	cout << "Hours: ";
	cin >> hrs;
	cout << "Minutes: ";
	cin >> min;
	cout << "Seconds: ";
	cin >> sec;

	clockType userClock(hrs, min, sec); // create a clock type based off of the user's inputs

	// demonstrate the elapsed_time() function
	cout << "Thank you. This is how much time has been elapsed in the day in seconds: " << userClock.elapsed_time() << endl; 
	// demonstrate the remaining_time() function
	cout << "This is how much time there is left in the day: " << userClock.remaining_time() << endl;
	// demonstrate the military_to_12() function
	userClock.military_to_12();
	cout << "This is the time in 12 hr format: ";
	userClock.print_time();
	// demonstrate the twelve_to_military function
	cout << "This is the time back into military format: ";
	userClock.twelve_to_military();
	userClock.print_time();

	system("pause");

	// declare our own clock for the final demonstration
	cout << endl << endl << "For the final demonstration, we set our own clock to 23:46:02. We can display the time difference between your clock and ours." << endl;
	clockType testClock(23, 46, 2);
	testClock.compare_time(userClock);


	system("pause");
	return 0;
}

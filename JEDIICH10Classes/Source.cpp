// jedii 10 29 18
// a program for practicing classes

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class clockType {
private:
	int hr;
	int min;
	int sec;

public:
	// these are our class constructors
	// normally in c++ they go on the bottom?
	// but i like python so they'll go up top
	clockType(int, int, int); // this one gets called if we're given paramaters
	clockType();

	// you need both set and get functions
	// you don't want to give names to the variables because these are classes, we need them to be generic
	// we declare these functions below main
	void set_time(int, int, int); // sets the time
	void get_time(int, int, int); // gets the time
	void print_time() const; // prints the time
	
	// our increment functions increment the time and then display the new one
	void increment_hours();
	void increment_mins();
	void increment_secs();

	// this function checks to see if the clock that's passed to it is the same as it's own clock
	bool equal_time(const clockType&) const; // mark clockType as constant because it's going in by reference
};

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

// get around to declaring our class' functions
// we have to use the scope resolution operator so that we can successfully declare it
void clockType::set_time(int hours, int minutes, int seconds) {
	// check and set our hours
	if (0 <= hours && hours < 24) hr = hours; // if hours is between 0-23, then set it...
	else hr = 0; // ...if not, just set it to 0

	// check and set our minutes
	if (0 <= minutes && minutes < 60) min = minutes; // if minutes is between 0-59, then set it...
	else min = minutes; // ...if not, just set it to 0

	// check and set our seconds
	if (0 <= seconds && seconds < 60) sec = seconds; // if seconds is between 0-59, then set it...
	else sec = seconds; // ...if not, just set it to 0
}

void clockType::print_time() const {
	// print the hour
	if (hr < 10) cout << '0'; // add padding if hour < 10
	cout << hr << ":";
	// print the minutes
	if (min < 10) cout << '0'; // add padding if min < 10
	cout << min << ":";
	// print the seconds
	if (sec < 10) cout << '0'; // add padding if sec < 10
	cout << sec << endl;
}

bool clockType::equal_time(const clockType& otherClock) const { // mark clockType as constant because it's going in by reference
	return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec); // return true if everything is equal
}

void clockType::increment_secs() {
	if (sec + 1 < 60) { // make sure that incrementing seconds doesn't equal 60
		sec++; // increment seconds
		print_time(); // print the new time
	}
	else { // if incrementing seconds does equal 60...
		sec = 0; // set seconds to 0
		increment_mins(); // then increment minutes
	}
}

void clockType::increment_mins() {
	if (min + 1 < 60) { // make sure that incrementing seconds doesn't equal 60
		min++; // increment seconds
		print_time(); // print the new time
	}
	else { // if incrementing seconds does equal 60...
		min = 0; // set seconds to 0
		increment_hours(); // then print the new time
	}
}

void clockType::increment_hours() {
	if (hr + 1 < 24) { // make sure that incrementing seconds doesn't equal 60
		hr++; // increment seconds
		print_time(); // print the new time
	}
	else { // if incrementing seconds does equal 60...
		hr = 0; // set seconds to 0
		print_time(); // then print the new time
	}
}

clockType::clockType(int hours, int minutes, int seconds) { // this is our class' constructor. this one gets called if we're given parameters
    // check and set our hours
	if (0 <= hours && hours < 24) hr = hours; // if hours is between 0-23, then set it...
	else hr = 0; // ...if not, just set it to 0

				 // check and set our minutes
	if (0 <= minutes && minutes < 60) min = minutes; // if minutes is between 0-59, then set it...
	else min = minutes; // ...if not, just set it to 0

						// check and set our seconds
	if (0 <= seconds && seconds < 60) sec = seconds; // if seconds is between 0-59, then set it...
	else sec = seconds; // ...if not, just set it to 0
}

clockType::clockType() { // this is another constructor of our class, but this one gets called if we're not given parameters
	hr = 12;
	min = 0;
	sec = 0;
}
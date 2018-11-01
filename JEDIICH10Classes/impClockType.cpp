#include <iostream>
#include <iomanip>
#include <string>
#include "clockType.h"

using namespace std;

// get around to declaring our class' functions
// we have to use the scope resolution operator so that we can successfully declare it
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
	cout << sec << " ";
	if (is12hr == true) { // check to see if it's in 12hr format to print the extension
		cout << timeOfDay << 'm' << endl;
	}
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

int clockType::elapsed_time() {
	bool twelveHrAtStart = is12hr; // keep track of whether it was 12hr format or not at the beginning of this function
	twelve_to_military(); // convert it to military time if it's not already

	// declare our variables for keeping track of our math
	int minutesElapsed, minutesTotal; // elapsed is our totals before the addition, total is the total after addition
	int secondsElapsed, secondsTotal;

	// do our calculations with the minutes
	// 1. multiply the # of hrs by 60 to get the number of minutes shown by the hours
	// 2. add that to the number of our minutes
	minutesElapsed = hr * 60; // get the number of minutes shown by the hours
	minutesTotal = minutesElapsed + min; // total all of our minutes

	// do our calculations with the seconds
	// 1. multiply the # of min by 60 to get the number of seconds shown by the minutes
	// 2. add that to the number of our seconds
	secondsElapsed = minutesTotal * 60; // get the number of seconds shown by the minutes
	secondsTotal = secondsElapsed + sec; // total all of our seconds

	if (twelveHrAtStart) military_to_12(); // convert it back to 12hr format if it was before this function ran

	return secondsTotal; // return our total number of seconds
}

void clockType::military_to_12() {
	if (is12hr == false) { // we only want to do this if it's not already in 12 hr format
		if (hr > 12) { // check to see if the number for hours is greater than 12
			hr = hr - 12; // reassign hour the number of hours it is over 12
			timeOfDay = 'p'; // set the time of day to pm
		}
		else if (hr == 12) timeOfDay = 'p'; // if the hr is equal to 12, then set the time of day to pm
		else if (hr == 0) { // if the hr is 0, then that means it's 12 am
			hr = 12; // set hr to 12
			timeOfDay = 'a'; // set time of day to am
		}
		else timeOfDay = 'a'; // set the time of day to am if hr isn't 0, 12, or anything above 12

		is12hr = true; // let the computer know what type of clock is saved
	}
}

void clockType::twelve_to_military() {
	if (is12hr == true) { // we only want to do this if it's not already in miltary format
		if (timeOfDay == 'p') { // check to see if the time of day is pm
			hr += 12; // if it is, add 12
			if (hr == 24) hr = 0; // if hr becomes 24 after this process, change it to 0
		}
		else { // this will run if the time is am
			if (hr == 12) hr = 0; // if it's 12 am, it will set the hr to 0
		}

		is12hr = false;
	}
}

int clockType::remaining_time() {
	bool twelveHrAtStart = is12hr; // create a variable for remembering if the clock is in 12 hr format
	twelve_to_military(); // convert the clock to military time, if it isn't already

	int secsLeft = 0; // create a variable for storing how many seconds are left in that day

	// a new day starts at 00:00:00
	// start by subtracting the seconds from 60 first
	secsLeft = 60 - sec;
	// then subtracting minutes from 59, then converting that to seconds
	int minsLeft = 59 - min;
	secsLeft += minsLeft * 60;
	// then subtract hours from 23, then convert that to minutes then seconds
	int hrsLeft = 23 - hr;
	minsLeft = hrsLeft * 60;
	secsLeft += minsLeft * 60;

	if (twelveHrAtStart) military_to_12(); // if it was in 12hr format before this function ran, convert it back

	return secsLeft; // return how many seconds are left in the day
}
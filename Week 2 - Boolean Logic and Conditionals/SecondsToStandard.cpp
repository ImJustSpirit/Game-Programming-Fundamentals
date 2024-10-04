#include <iostream>

using namespace std;

int main() {
	int input;
	int seconds;
	int minutes;
	int hours;

	cout << "Enter a time in seconds: ";
	cin >> input;
	seconds = input;

	hours = seconds / 3600;
	seconds = seconds % 3600;

	minutes = seconds / 60;
	seconds = seconds % 60;

	cout << input << " seconds is " << hours << ":" << minutes << ":" << seconds;
}
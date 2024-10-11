#include <iostream>

using namespace std;

int main()
{
	//First we ask for the current temp in Fahrenheit
	cout << "Please input your temperature in Fahrenheit: ";

	//Create the int and then store the value
	int f;
	cin >> f;

	// Output the value, and the converted value
	cout << "Your temperature (" << f << "F) is " << (f - 32) * 5 / 9 << " in Celsius.";
}
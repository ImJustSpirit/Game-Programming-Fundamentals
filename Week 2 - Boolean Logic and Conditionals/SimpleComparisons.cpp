#include <iostream>

using namespace std;

int main() {
	int numOne;
	int numTwo;

	cout << "Enter number one: ";
	cin >> numOne;

	cout << "Enter number two: ";
	cin >> numTwo;

	if (numOne > numTwo) {cout << numOne << " is bigger than " << numTwo;}
	else if (numTwo > numOne) {cout << numTwo << " is bigger than " << numOne;}
	else if (numOne == numTwo) { cout << numOne << " and " << numTwo << " are exactly the same";}
}
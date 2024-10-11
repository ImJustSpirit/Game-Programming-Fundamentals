#include <iostream>

using namespace std;

int main() {
	int numOne;
	int numTwo;

	cout << "Enter a number: ";
	cin >> numOne;

	cout << "Enter a number: ";
	cin >> numTwo;

	numOne += numTwo;
	numTwo = numOne - numTwo;
	numOne -= numTwo;

	cout << numOne << endl;
	cout << numTwo << endl;
}
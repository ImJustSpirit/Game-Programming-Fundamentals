#include <iostream>

using namespace std;

int main() {
	int numOne;
	int numTwo;

	cout << "Enter the bigger number: ";
	cin >> numOne;

	cout << "Enter the smaller number: ";
	cin >> numTwo;

	cout << "The remainder of " << numOne << " and " << numTwo << " is: " << numOne % numTwo;
}
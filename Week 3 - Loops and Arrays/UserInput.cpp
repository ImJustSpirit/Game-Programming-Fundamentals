#include <iostream>

using namespace std;

int main() {
	int numOne;
	int numTwo;
	char choice;

	cout << "Enter number one: ";
	cin >> numOne;

	cout << "Enter number two: ";
	cin >> numTwo;

	while (true) {
		cout << "\nWhat would you like to do with your numbers?\n1) Add them\n2) Multiply them\n3) Divide them\nQ) Exit\n";
		cin >> choice;

		if (choice == '1') { cout << numOne + numTwo; }
		else if (choice == '2') { cout << numOne * numTwo; }
		else if (choice == '3') { cout << numOne / numTwo; }
		else if (choice == 'q' || choice == 'Q') { break; }
	}
}
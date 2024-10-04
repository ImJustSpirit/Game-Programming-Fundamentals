#include <iostream>

using namespace std;

int main() {
	bool innerDoor = true;
	bool outerDoor = true;
	int choice;

	while (true) {
		if (innerDoor) { cout << "The inner door is closed." << endl; }
		else { cout << "The inner door is open." << endl; }

		if (outerDoor) { cout << "The outer door is closed." << endl; }
		else { cout << "The outer door is open." << endl; }

		cout << "\nWhat would you like to do?\n1) Press button for inner door\n2) Press button for outer door\n3) Wait\n";
		cin >> choice;

		if (choice == 1) {
			if (innerDoor) {
				cout << "Inner door is now open.\n\n";
				innerDoor = false;
			}
			else {
				cout << "Inner door is now closed.\n\n";
				innerDoor = true;
			}
		}

		if (choice == 2) {
			if (outerDoor) {
				cout << "Outer door is now open.\n\n";
				outerDoor = false;
			}
			else {
				cout << "Outer door is now closed.\n\n";
				outerDoor = true;
			}
		}

		if (!innerDoor && !outerDoor) {
			cout << "Oh no! Basil has escaped!";
			break;
		}
	}
}
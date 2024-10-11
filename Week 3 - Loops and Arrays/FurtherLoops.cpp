#include <iostream>

using namespace std;

int main() {
	int numbers[100];
	int count;
	int check = 0;

	cout << "Please enter how many numbers you want to input (1-100): ";
	cin >> count;

	for (int i = 0; i < count; i++) {
		cout << "Enter a number: ";
		cin >> numbers[i];
	}

	for (int i = 0; i < count; i++) {
		if (numbers[i] % 2 == 1) { cout << numbers[i] << " is an odd number." << endl; }
		if (numbers[i] > 1) {
			for (int n = 1; n <= numbers[i]; n++) {
				if (numbers[i] % n == 0) { check++; }
			}
			if (check < 3) { cout << numbers[i] << " is a prime number." << endl; }
			check = 0;
		}
	}
}
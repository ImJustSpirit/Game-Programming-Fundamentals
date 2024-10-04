#include <iostream>

using namespace std;

int main() {
	int results[6];
	int average;

	cout << "Enter result one: ";
	cin >> results[0];

	cout << "Enter result two: ";
	cin >> results[1];

	cout << "Enter result three: ";
	cin >> results[2];

	cout << "Enter result four: ";
	cin >> results[3];

	cout << "Enter result five: ";
	cin >> results[4];

	cout << "Enter result six: ";
	cin >> results[5];

	average = (results[0] + results[1] + results[2] + results[3] + results[4] + results[5]) / 6;

	if (average >= 85) { cout << "The student has passed with the final grade of A* and an average of " << average; }
	else if (average >= 70) { cout << "The student has passed with the final grade of A and an average of " << average; }
	else if (average >= 60) { cout << "The student has passed with the final grade of B and an average of " << average; }
	else if (average >= 50) { cout << "The student has passed with the final grade of C and an average of " << average; }
	else if (average >= 40) { cout << "The student has passed with the final grade of D and an average of " << average; }
	else if (average >= 30) { cout << "The student has failed with the final grade of E and an average of " << average; }
	else { cout << "The student has failed with the final grade of E and an average of " << average; }
}
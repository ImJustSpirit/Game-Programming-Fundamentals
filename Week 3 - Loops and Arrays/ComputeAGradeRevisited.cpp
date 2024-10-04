#include <iostream>

using namespace std;

int main() {
	int results[6];
	int average;

	for (int i = 0; i < 6; i++) {
		cout << "Enter a result: ";
		cin >> results[i];
	}

	average = (results[0] + results[1] + results[2] + results[3] + results[4] + results[5]) / 6;

	if (average >= 85) { cout << "The student has passed with the final grade of A* and an average of " << average << endl; }
	else if (average >= 70) { cout << "The student has passed with the final grade of A and an average of " << average << endl; }
	else if (average >= 60) { cout << "The student has passed with the final grade of B and an average of " << average << endl; }
	else if (average >= 50) { cout << "The student has passed with the final grade of C and an average of " << average << endl; }
	else if (average >= 40) { cout << "The student has passed with the final grade of D and an average of " << average << endl; }
	else if (average >= 30) { cout << "The student has failed with the final grade of E and an average of " << average << endl; }
	else { cout << "The student has failed with the final grade of E and an average of " << average << endl; }


	for (int i = 0; i < 6; i++) {
		if (results[i] < 40) { cout << "The student has failed module " << i + 1 << " with a score of " << results[i] << endl; }
	}
}
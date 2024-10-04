#include <iostream>

using namespace std;

int main() {
	int numbers[10] = { 10, 9, 8, 7, 6 };
	int n = 1;

	for (int i = 5; i < 10; i++) {
		numbers[i] = numbers[i-n];
		n += 2;
	}

	for (int i = 0; i < 10; i++) { cout << numbers[i] << endl; }
}
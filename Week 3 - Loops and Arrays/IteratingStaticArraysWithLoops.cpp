#include <iostream>

using namespace std;

int main() {
	int ages[10] = { 29, 34, 21, 19, 16, 45, 34, 57, 99, 40 };

	for (int i = 0; i < 10; i++) { cout << ages[i] << endl; }
	cout << endl;
	for (int i = 9; i > -1; i--) { cout << ages[i] << endl; }
}
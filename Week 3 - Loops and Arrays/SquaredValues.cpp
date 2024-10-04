#include <iostream>

using namespace std;

int main() {
	int squares[20];

	for (int i = 0; i < 20; i++) { squares[i] = i*i; }

	for (int i = 0; i < 20; i++) { cout << squares[i] << endl; }
	cout << endl;
	for (int i = 19; i > -1; i--) { cout << squares[i] << endl; }
}
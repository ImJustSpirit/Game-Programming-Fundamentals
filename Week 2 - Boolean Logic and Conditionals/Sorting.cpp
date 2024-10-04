#include <iostream>

using namespace std;

int main() {
	int firstNum;
	int secondNum;
	int thirdNum;

	cout << "Enter your first number: ";
	cin >> firstNum;

	cout << "Enter your second number: ";
	cin >> secondNum;

	cout << "Enter your third number: ";
	cin >> thirdNum;

	if (firstNum < secondNum) {
		if (secondNum < thirdNum) { cout << firstNum << " " << secondNum << " " << thirdNum; }
		else if (firstNum < thirdNum) { cout << firstNum << " " << thirdNum << " " << secondNum; }
		else { cout << thirdNum << " " << firstNum << " " << secondNum; }
	}
	else if (firstNum < thirdNum) { cout << secondNum << " " << firstNum << " " << thirdNum; }
	else {
		if (secondNum < thirdNum) { cout << secondNum << " " << thirdNum << " " << firstNum; }
		else { cout << thirdNum << " " << secondNum << " " << firstNum; }
	}
}
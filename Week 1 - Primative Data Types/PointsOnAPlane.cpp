#include <iostream>

using namespace std;

int main() {
	int pointA[2];
	int pointB[2];
	float distance;

	cout << "Please enter the X coordinate for the first point: ";
	cin >> pointA[0];

	cout << "Please enter the Y coordinate for the first point: ";
	cin >> pointA[1];

	cout << "Please enter the X coordinate for the second point: ";
	cin >> pointB[0];

	cout << "Please enter the Y coordinate for the second point: ";
	cin >> pointB[1];

	distance = sqrt(pow(abs(pointB[0] - pointA[0]), 2) + pow(abs(pointB[1] - pointA[1]), 2));

	cout << "The distance between point A and point B is " << distance;
}
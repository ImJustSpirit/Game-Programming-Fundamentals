/*
    Start shape drawing file
*/

#include <iostream>
#include "Framework.h"

// Variables with global scope - do not rename them, feel free to change values though

// Screen dimensions
int gScreenWidth{800};
int gScreenHeight{600};

// Delay to slow things down
int gTimeDelayMS{1};

using namespace std;

int main()
{
	srand(time(NULL));

	int x[100];
	int y[100];
	bool xDir[100];
	bool yDir[100];

	for (int i = 0; i < 100; i++) {
		x[i] = rand() % gScreenWidth;
		y[i] = rand() % gScreenHeight;
		if (rand() % 2 == 1) { xDir[i] = true; }
		else { xDir[i] = false; }
		if (rand() % 2 == 1) { yDir[i] = true; }
		else { yDir[i] = false; }
	}

	while(UpdateFramework())
	{
		for (int i = 0; i < 100; i++) {
			DrawCircle(x[i], y[i], 20);

			if (!xDir[i]) {
				x[i]++;
				if (x[i] >= gScreenWidth - 40) { xDir[i] = true; }
			} 
			else {
				x[i]--;
				if (x[i] <= 0) { xDir[i] = false; }
			}

			if (!yDir[i]) {
				y[i]++;
				if (y[i] >= gScreenHeight - 40) { yDir[i] = true; }
			}
			else {
				y[i]--;
				if (y[i] <= 0) { yDir[i] = false; }
			}
		}
	}
	return 0;
}

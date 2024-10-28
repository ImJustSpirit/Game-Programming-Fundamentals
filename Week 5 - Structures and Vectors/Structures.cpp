/*
	Start shape drawing file
*/

#include <iostream>
#include "Framework.h"

// Variables with global scope - do not rename them, feel free to change values though

// Screen dimensions
int gScreenWidth{ 800 };
int gScreenHeight{ 600 };

// Delay to slow things down
int gTimeDelayMS{ 1 };

using namespace std;

int main()
{
	srand(time(NULL));

	struct Circles {
		int x;
		int y;
		bool xDir;
		bool yDir;
	};

	Circles ball[100];

	for (int i = 0; i < 100; i++) {
		ball[i].x = rand() % gScreenWidth;
		ball[i].y = rand() % gScreenHeight;
		if (rand() % 2 == 1) { ball[i].xDir = true; }
		else { ball[i].xDir = false; }
		if (rand() % 2 == 1) { ball[i].yDir = true; }
		else { ball[i].yDir = false; }
	}

	while (UpdateFramework())
	{
		for (int i = 0; i < 100; i++) {
			DrawCircle(ball[i].x, ball[i].y, 20);

			if (!ball[i].xDir) {
				ball[i].x++;
				if (ball[i].x >= gScreenWidth - 40) { ball[i].xDir = true; }
			}
			else {
				ball[i].x--;
				if (ball[i].x <= 0) { ball[i].xDir = false; }
			}

			if (!ball[i].yDir) {
				ball[i].y++;
				if (ball[i].y >= gScreenHeight - 40) { ball[i].yDir = true; }
			}
			else {
				ball[i].y--;
				if (ball[i].y <= 0) { ball[i].yDir = false; }
			}
		}
	}
	return 0;
}

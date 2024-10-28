/*
	Start shape drawing file
*/

#include <iostream>
#include "Framework.h"
#include <vector>

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

	int mousX;
	int mousY;

	int speed = 5;

	struct Circles {
		int x;
		int y;
		bool xDir;
		bool yDir;
		int colour[3];
	};

	vector<Circles> circlesVector;
	Circles ball;

	ball.x = rand() % gScreenWidth;
	ball.y = rand() % gScreenHeight;

	if (rand() % 2 == 1) { ball.xDir = true; }
	else { ball.xDir = false; }

	if (rand() % 2 == 1) { ball.yDir = true; }
	else { ball.yDir = false; }

	circlesVector.push_back(ball);

	while (UpdateFramework())
	{
		for (int i = 0; i < circlesVector.size(); i++) {
			DrawCircle(circlesVector[i].x, circlesVector[i].y, 20);
			if (IsButtonPressed(EButton::eLeft)) { 
				GetMousePosition(mousX, mousY);
				if (mousX < circlesVector[i].x) { circlesVector[i].x -= speed; }
				else { circlesVector[i].x += speed; }
				if (mousY < circlesVector[i].y) { circlesVector[i].y -= speed; }
				else { circlesVector[i].y += speed; }
			}
			else {
				if (!circlesVector[i].xDir) {
					circlesVector[i].x += speed;
					if (circlesVector[i].x >= gScreenWidth - 40) { circlesVector[i].xDir = true; }
				}
				else {
					circlesVector[i].x -= speed;
					if (circlesVector[i].x <= 0) { circlesVector[i].xDir = false; }
				}

				if (!circlesVector[i].yDir) {
					circlesVector[i].y += speed;
					if (circlesVector[i].y >= gScreenHeight - 40) { circlesVector[i].yDir = true; }
				}
				else {
					circlesVector[i].y -= speed;
					if (circlesVector[i].y <= 0) { circlesVector[i].yDir = false; }
				}
			}
		}
		if (IsButtonPressed(EButton::eRight)) {
			Circles ball;
			GetMousePosition(ball.x, ball.y);
			if (rand() % 2 == 1) { ball.xDir = true; }
			else { ball.xDir = false; }
			if (rand() % 2 == 1) { ball.yDir = true; }
			else { ball.yDir = false; }
			circlesVector.push_back(ball);
		}
	}
	return 0;
}
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirextion { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirextion dir;

void Setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % (width - 2) + 1;
	fruitY = rand() % (height - 2) + 1;
	score = 0;
}

void Draw() {
	system("cls");

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else if (j == 0 || i == 0 || i == height - 1 || j == width - 1)
				cout << "#";
			else {
				bool print = false;
				//for (int k = 0; i < nTail; k++) {
					//if (tailX[k] == j && tailY[k] == i) {
						// cout << "o";
						print = true;
					//}
				//}
				//if(!print)
					cout << " ";
			}// else
		}
		cout << endl;
	}
	cout << "Score : " << score << endl;
}// Draw

void Input() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}// Input

void Logic() {
	/*
	tailX[0] = x;
	tailY[0] = y;
	int prevX = tailX[0];
	int prevY = tailY[0];
	int tempX, tempY;

	for (int i = 1; i < nTail; i++) {
		tempX = tailX[i];
		tempY = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = tempX;
		prevY = tempY;
	}
	*/

	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	// #을 만나면 gameOver
	// if (x > width-1 || x < 1 || y>height-1 || y < 1)
		// gameOver = true;

	if (x >= width)x = 0;
	else if (x < 0)x = width - 1;
	if (y >= height)y = 0;
	else if (y < 0)y = height - 1;

	// tail을 만나면 gameover
	//for (int i = 0; i < nTail; i++)
		//if (tailX[i] == x && tailY[i] == y)
			//gameOver = true;

	if (x == fruitX && y == fruitY) {
		score += 1;
		// # 안밟고 싶은데..
		fruitX = rand() % (width - 2) + 1;
		fruitY = rand() % (height - 2) + 1;
		nTail++;
	}
} // Logic

int main() {
	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
		Sleep(50); // sleep(10);
	}
	return 0;
}
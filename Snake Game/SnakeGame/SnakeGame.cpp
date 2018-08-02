﻿// SnakeGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
using namespace std;

static int height=20, width=20;
bool GameOver;
int x, y,fruitX,fruitY,score=0,a,b,sleep_interval=70,nTail=0,tailX[50],tailY[50];
enum Edirection{STOP=0,LEFT,RIGHT,UP,DOWN};
Edirection dir;


void Setup()
{
	GameOver = false;
	dir = STOP;
	x = width % 2;
	y = height % 2;
	fruitX = rand() % width;
	fruitY = rand() % height;

}


void Logic()
{
	int prevX, prevY, prev2X, prev2Y;
	prevX = tailX[0];
	prevY = tailY[0];
	tailX[0] = x, tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case RIGHT:
		x++;
		break;
	case LEFT:
		x--;
		break;
	default :
		break;
	}

	/*if (x > width || x< 0 || y > height || y < 0)
	{									//IN ORDER TO LOCK BOUNDARIES FOR SNAKE REMOVE THESE AS COMMENT
		GameOver = true;
	}*/
	
	if (x > width) x = 0; if (x < 0) x = width - 1;				//PUT THESE TO LINES AS COMMENT TO LOCK BOUNDRIES FOR SNAKE
	if (y > height) y = 0; if (y < 0) y = height - 1;

	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			GameOver = true;
		}
	}
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;

		nTail += 1;


		if (sleep_interval > 1)
		sleep_interval -= 5;
		
	}
	cout << "Score: " << score << endl;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			dir = UP;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;

		case 'x':
			GameOver = true;
			break;
		}

	}

}
 
void Draw()
{
	
	system("cls");
	for ( a = 0; a < width + 2; a++)
	{
		cout << "* ";
	}
	cout << "\n";
	for (a = 0; a < height; a++)
	{
		for (b = 0; b < width; b++)
		{


			if (b == 0)
			{
				cout << "* ";
			}


			if (a == y && b == x)
			{
				cout << "O ";
			}

			else if (a == fruitY && b == fruitX)
			{
				cout << "F ";
			}

			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
					{
						if (tailX[k] == b && tailY[k] == a)
							{
								cout << "o ";
								print = true;
							}
					}

				if (!print)
				cout << "  ";
			}
		

		if( b == width - 1)
			{
			cout << "* ";
			}

	}
	cout << endl;

}
for (a = 0; a <width + 2; a++)
{
	cout << "* ";
}
cout << endl;
}



int main()
{
	Setup();
	while (!GameOver)
	{
		Draw();
		Input();
		Logic();
		if (sleep_interval == 1)
		cout << "Full Speed!" << endl;
		Sleep(sleep_interval);
	}
	
    return 0;
	
}


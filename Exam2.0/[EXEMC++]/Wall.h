#pragma once
#include <iostream>
#include <string> 
#include <conio.h>
#include <windows.h>
using namespace std;
class Wall
{
	string ui;
	int x;
	int y;
	int width;
	int height;
	void setCursor(int x, int y) {
		COORD position = { x,y };
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, position);
	}
public:
	Wall(string ui, int x, int y, int width, int height) {
		this->ui = ui;
		this->width = width;
		this->height = height;
		this->x = x;
		this->y = y;
	};
	~Wall() {};

	int getX()const& { return this->x; };
	int getY()const& { return this->y; };
	int getWidth()const& { return this->width; };
	int getHeight()const& { return this->height; };

	void draw() {
		for (int i = 0; i < height; i++) {
			setCursor(x, y + i);
			cout << this->ui;
		}
	};
};


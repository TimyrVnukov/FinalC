#pragma once
#include <iostream>
#include <string> 
#include <conio.h>
#include <windows.h>
using namespace std;
#include "Player.h"
class Teleport
{
	string* ui;
	int x;
	int y;
	int width;
	int height;
	int level;
	int room;
	void setCursor(int x, int y) {
		COORD position = { x,y };
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, position);
	}
public:
	Teleport(string* ui, int x, int y, int width, int height, int level, int room) {
		this->ui = ui;
		this->width = width;
		this->height = height;
		this->x = x;
		this->y = y;
		this->level = level;
		this->room = room;
	};
	~Teleport() {};
	int getLevel()const& { return this->level; };
	int getRoom()const& { return this->room; };
	bool vision(Player& player, int count) {
		int countHeight = int(count / 2);
		if (player.getX() + player.getWidth() >= x - count && player.getX() <= x + width + count && player.getY() + player.getHeight() >= y - countHeight && player.getY() <= y + height + countHeight) {
			return true;
		}
		else {
			return false;
		}
	}
	void draw() {
		for (int i = 0; i < height; i++) {
			setCursor(x, y + i);
			cout << this->ui[i];
		}
	};
};


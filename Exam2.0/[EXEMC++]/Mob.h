#pragma once
#include <iostream>
#include <string> 
#include <conio.h>
#include <windows.h>
using namespace std;
#include "Player.h"
class Mob
{
	string* ui;
	int x;
	int y;
	int width;
	int height;
	int hp;
	int damage;
	int walkKD;//100 = 1second
	int walkTime;
	int hitKD;//100 = 1second
	int hitTime;
	void setCursor(int x, int y) {
		COORD position = { x,y };
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, position);
	}
public:
	Mob(string* ui, int x, int y, int width, int height, int hp, int damage, int walkKD, int hitKD) {
		this->ui = ui;
		this->width = width;
		this->height = height;
		this->x = x;
		this->y = y;
		this->hp = hp;
		this->damage = damage;
		this->walkKD = walkKD;
		this->walkTime = walkKD;
		this->hitKD = hitKD;
		this->hitTime = hitKD;
	};
	~Mob() {};
	int getX() { return this->x; };
	int getY() { return this->y; };
	int getWidth() { return this->width; };
	int getHeight() { return this->height; };
	int getHp() { return this->hp; };

	void draw() {
		for (int i = 0; i < height; i++) {
			setCursor(x, y + i);
			cout << this->ui[i];
		}
	};
	void clear() {
		for (int i = 0; i < height; i++) {
			setCursor(x, y + i);
			for (int j = 0; j < width; j++) {
				setCursor(x + j, y + i); cout << " ";
			}
		}
	};
	bool vision(Player& player, int count) {
		int countHeight = int(count / 2);
		if (player.getX() + player.getWidth() >= x - count && player.getX() <= x + width + count && player.getY() + player.getHeight() >= y - countHeight && player.getY() <= y + height + countHeight) {
			return true;
		}
		else {
			return false;
		}
	}
	virtual void Mob_vision(Player& player, int count) {
		if (vision(player, count)) {
			Fight(player);
		}
	}
	void WalkTimer(Player& player, int count) {
		if (vision(player, count)) {
			this->walkTime--;
			if (walkTime < 0) {
				walkTime = walkKD;
				gotoPlayer(player, count);
			}
		}
	}
	virtual void gotoPlayer(Player& player, int count) {
		if (this->hp > 0) {
			clear();
			if (player.getX() < x) {
				x--;
			}
			else if (player.getX() > x) {
				x++;
			}
			else if (player.getY() < y) {
				y--;
			}
			else if (player.getY() > y) {
				y++;
			}
			draw();
		}
		else {
			clear();
		}
	}
	virtual void Fight(Player& player) {
		this->hitTime--;
		if (hitTime < 0) {
			hitTime = hitKD;
			player.setHp(10);
			player.showHp();
		}
		if (_kbhit())
		{
			switch (_getch())
			{
			case (int)'e':
				this->hp -= 50;
				break;
			}
		}
	}
};


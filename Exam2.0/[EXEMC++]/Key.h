#pragma once
#include <iostream>
#include <string> 
#include <conio.h>
#include <windows.h>
using namespace std;
#include "Player.h"
class Key
{
	string* ui;
	int x;
	int y;
	int width;
	int height;
	int hp;
	int damage;
	
	int score=0;
	int hitKD;//100 = 1second
	int hitTime;
	void setCursor(int x, int y) {
		COORD position = { x,y };
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, position);
	}
public:
	Key(string* ui, int x, int y, int width, int height, int hp, int damage,  int hitKD) {
		this->ui = ui;
		this->width = width;
		this->height = height;
		this->x = x;
		this->y = y;
		this->hp = hp;
		this->damage = damage;
		
		this->hitKD = hitKD;
		this->hitTime = hitKD;
	};
	~Key() {};
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
	virtual void Key_vision(Player& player, int count) {
		if (vision(player, count)) {
			OpenKey(player);
			
		}
	
	}
	
	void setCatana() {
		setCursor(60, 60);
		cout << "---------------------" << endl;
		setCursor(60, 61);
		cout << "|   /|    |    |    |" << endl;
		setCursor(60, 62);
		cout << "| /  |    |    |    |" << endl;
		setCursor(60, 63);
		cout << "---------------------";
	}

	virtual void OpenKey(Player& player) {
		this->hitTime--;
		if (hitTime < 0) {
			hitTime = hitKD;	
		}
		if (_kbhit())
		{
			switch (_getch())
			{
			case (int)'e':
				this->hp -= 1000;
				break;
			}
		}
	}
	
};


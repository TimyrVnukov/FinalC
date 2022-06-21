#pragma once
#include "Mob.h"
class BossSlime:public Mob
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
	BossSlime(string* ui, int x, int y, int width, int height, int hp, int damage, int walkKD, int hitKD):Mob(ui, x, y, width, height, hp, damage, walkKD, hitKD) {
		
	};
	~BossSlime() {};
	virtual void gotoPlayer(Player& player, int count) {
		
	}
	virtual void Mob_vision(Player& player, int count) {
		if (vision(player, count + 4)) {
			Fight(player);
		}
	}
	virtual void Fight(Player& player) {
		this->hitTime--;
		if (hitTime < 0) {
			hitTime = hitKD;
			setCursor(0, 0); cout << "!";
			//player.setHp(10);
			//player.showHp();
		}
	}
};


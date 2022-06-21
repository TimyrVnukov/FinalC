#pragma once
#include <fstream>
#include <iostream>
#include <string> 
#include <conio.h>
#include <windows.h>
#include "Walls.h"
using namespace std;
class Player
{
	int x;
	int y;
	int width;
	int height;
	string ui[3] = { "*-*", "| |", "*-*" };
    int hp;
    int score;
    bool enemtyCollider[4] = { false, false, false, false };
	void setCursor(int x, int y) {
		COORD position = { x,y };
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, position);
	}
public:
    Player() {
        this->x = 0;
        this->y = 0;
        this->width = 0;
        this->height = 0;
        this->hp = 100;
    };
	Player(int x, int y) {
		this->x = x;
		this->y = y;
		this->width = 3;
		this->height = 3;
        this->hp = 100;
	};
	~Player() {};
    int getX()const& { return this->x; };
    int getY()const& { return this->y; };
    int getWidth()const& { return this->width; };
    int getHeight()const& { return this->height; };
    int getHp()const& { return this->hp; };
    void setHp(int hp) { this->hp -= hp; };
    void setScore(int score) { this->score += score; };
    void setHpHIL(int hp) { this->hp += hp; };
	void draw() {
		for (int i = 0; i < 3; i++) {
			setCursor(x, y + i);
			cout << this->ui[i];
		}
	}
    void clear() {
        for (int i = 0; i < 3; i++) {
            setCursor(x, y + i);
            cout << "   ";
        }
    }
    void showHp() {
        setCursor(100, 60);
        cout << "hp:           ";
        setCursor(100, 60);
        cout << "hp: " << this->hp;
        int tmpHP = this->hp;
        setCursor(100, 61);
        cout << "                  ";
        for (int i = 0; i <= 10; i++) {
            if (tmpHP >= 10) {
                tmpHP -= 10;
                setCursor(100 + i, 61); cout << "#";
            }
        }
    }
    void showScore() {
        setCursor(20, 60);
        cout << "Score:           ";
        setCursor(20, 60);
        cout << "Score: " << this->score;
        ofstream out;          
        out.open("E:\\!repos\\Exam2.0\\exam.txt"); 
        if (out.is_open())
        {
            out << this->score << endl;
        }  
        int tmpScore = this->score;
        setCursor(20, 61);
        cout << "                  ";
        for (int i = 0; i <= 10; i++) {
            if (tmpScore >= 1) {
                tmpScore += 1;
                setCursor(20 + i, 61); cout << "$";
            }
        }
    }

    void setPlayerPosition(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void inventar() {
        setCursor(60, 60);
        setCursor(60, 60);
        cout << "---------------------" << endl;
        setCursor(60, 61);
        cout << "|    |    |    |    |" << endl;
        setCursor(60, 62);
        cout << "|    |    |    |    |" << endl;
        setCursor(60, 63);
        cout << "---------------------";

        int tmpHP2 = this->hp;
        if (tmpHP2 > 100){
            setCursor(60, 60);
            cout << "---------------------" << endl;
            setCursor(60, 61);
            cout << "|    | -- |    |    |" << endl;
            setCursor(60, 62);
            cout << "|    | -- |    |    |" << endl;
            setCursor(60, 63);
            cout << "---------------------";
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

    void setHilka() {
        setCursor(60, 60);
        cout << "---------------------" << endl;
        setCursor(60, 61);
        cout << "|    | -- |    |    |" << endl;
        setCursor(60, 62);
        cout << "|    | -- |    |    |" << endl;
        setCursor(60, 63);
        cout << "---------------------";
    }
    void setCatanaANDhilka() {
        setCursor(60, 60);
        cout << "---------------------" << endl;
        setCursor(60, 61);
        cout << "|   /| -- |    |    |" << endl;
        setCursor(60, 62);
        cout << "| /  | -- |    |    |" << endl;
        setCursor(60, 63);
        cout << "---------------------";
    }


    void setEnemtyColliders(string direction, bool set) {
        if (direction == "left") {
            this->enemtyCollider[0] = set;
        }
        else if (direction == "top") {
            this->enemtyCollider[1] = set;
        }
        else if (direction == "right") {
            this->enemtyCollider[2] = set;
        }
        else if (direction == "bottom") {
            this->enemtyCollider[3] = set;
        }
    };
    bool getEnemtyColliders(string direction) {
        if (direction == "left") {
            return this->enemtyCollider[0];
        }
        else if (direction == "top") {
            return this->enemtyCollider[1];
        }
        else if (direction == "right") {
            return this->enemtyCollider[2];
        }
        else if (direction == "bottom") {
            return this->enemtyCollider[3];
        }
    };

    bool iscanMoveRight(int widthMap, int heightMap) {
        if (x > widthMap - 1 - this->width) {
            return false;
        }
        return true;
    }
    bool iscanMoveLeft(int widthMap, int heightMap) {
        if (x <= 1) {
            return false;
        }
        return true;
    }
    bool iscanMoveTop(int widthMap, int heightMap) {
        if (y <= 1) {
            return false;
        }
        return true;
    }
    bool iscanMoveBottom(int widthMap, int heightMap) {
        if (y > heightMap - this->height) {
            return false;
        }
        return true;
    }
	void movement(int widthMap, int heightMap) {
        if (_kbhit())
        {
            switch (_getch())
            {
            case (int)'w':
                if (iscanMoveTop(widthMap, heightMap) && !getEnemtyColliders("top")) {
                    clear();
                    y--;
                    draw();
                }
                break;
            case (int)'a':
                if (iscanMoveLeft(widthMap, heightMap) && !getEnemtyColliders("left")) {
                    clear();
                    x--;
                    draw();
                }
                break;
            case (int)'d':
                if (iscanMoveRight(widthMap, heightMap) && !getEnemtyColliders("right")) {
                    clear();
                    x++;
                    draw();
                }
                break;
            case (int)'s':
                if (iscanMoveBottom(widthMap, heightMap) && !getEnemtyColliders("bottom")) {
                    clear();
                    y++;
                    draw();
                }
                break;
            }
        }
	}
};


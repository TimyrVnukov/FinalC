#pragma once
#include <iostream>
#include <string> 
#include <conio.h>
#include <windows.h>
using namespace std;
#include "Wall.h"
class Walls
{
	Wall** arr;
	int index;
public:
	Walls() {
		this->arr = NULL;
		this->index = 0;
	};
	~Walls() {
		if (index > 0) {
			for (int i = 0; i < this->index; i++) {
				delete arr[i];
			}
			delete[] arr;
		}
	};

	int getIndex()const& { return this->index; };

	void addItem(Wall* obj) {
		Wall** tmp = new Wall * [++index];
		for (int i = 0; i < index - 1; i++) {
			tmp[i] = arr[i];
		}
		if (arr != NULL) {
			delete[]arr;
		}
		tmp[index - 1] = obj;
		arr = tmp;
	};

	void deleteItem(int n) {
		Wall** tmp = new Wall * [--this->index];
		for (int i = 0; i < n; i++) {
			tmp[i] = arr[i];
		}
		cout << endl;
		for (int i = n; i < index; i++) {
			tmp[i] = arr[i + 1];
		}
		arr = tmp;
		for (int i = 0; i < index; i++) {
			arr[i] = tmp[i];
		}
	};
	void deleteAll() {
		this->arr = NULL;
		this->index = 0;
	}
	Wall* operator[](int n) {
		if (n >= 0 && n < index) {
			return this->arr[n];
		}
		else {
			throw "Out of range";
		}
	};
	void draw() {
		for (int i = 0; i < index; i++) {
			arr[i]->draw();
		}
	}
};


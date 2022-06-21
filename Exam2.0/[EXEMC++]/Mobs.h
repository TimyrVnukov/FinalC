#pragma once
#include "Mob.h"
class Mobs
{
	Mob** arr;
	int index;
public:
	Mobs() {
		this->arr = NULL;
		this->index = 0;
	};
	~Mobs() {
		if (index > 0) {
			for (int i = 0; i < this->index; i++) {
				delete arr[i];
			}
			delete[] arr;
		}
	};

	int getIndex()const& { return this->index; };

	void addItem(Mob* obj) {
		Mob** tmp = new Mob * [++index];
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
		Mob** tmp = new Mob * [--this->index];
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
	Mob* operator[](int n) {
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


#pragma once
#include "Box.h"
class Boxs
{
	Box** arr;
	int index;
public:
	Boxs() {
		this->arr = NULL;
		this->index = 0;
	};
	~Boxs() {
		if (index > 0) {
			for (int i = 0; i < this->index; i++) {
				delete arr[i];
			}
			delete[] arr;
		}
	};

	int getIndex()const& { return this->index; };

	void addItem(Box* obj) {
		Box** tmp = new Box * [++index];
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
		Box** tmp = new Box * [--this->index];
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
	Box* operator[](int n) {
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


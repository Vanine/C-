#pragma once

class Vector {
	private:
	int length;
	int capacity;
	int* arr;
	public:
    Vector();
	void insert(int value);
	void display();
	void insertAt(int index, int value);
	void deleteItem(int index);
	int get(int index);
	int indexOf(int value);
	void sort();
};


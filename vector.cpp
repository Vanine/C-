#include <iostream>
using namespace std;

class Vector {
	private:
	int length;
	int capacity;
	int* arr;
	public:
	int pop();
	void push(int newItem);
	void display();
	void insertPos(int position, int newItem);
	int deletePos(int position);
	Vector(){
		length=0;
		capacity=1;
		arr = new int[capacity];
	}
};


void Vector::display() {
	for(int i = 0; i < length; i++) {
		cout << arr[i] << endl;
	}
}

void Vector::push(int newItem) {
	if(length == capacity) {
		capacity *= 2;
		int* newArray = new int[capacity];
		for(int i = 0; i < length; i++) {
			newArray[i] = arr[i];
		}
		newArray[length] = newItem;
		arr = newArray;
	}
	else {
		arr[length] = newItem;
	}
		length++;
}

int Vector::pop() {
		int temp = arr[length-1];
		arr[length-1] = NULL;
		length--;
		return temp;
}

void Vector::insertPos(int position, int newItem) {
	if(position < 0 || position >= length) return;
		capacity++;
		int* newArray = new int[capacity];
		int i = 0;
		for (int i = 0; i < position; i++) {
			newArray[i] = arr[i];
		}
		newArray[position] = newItem;
		for (i = position+1; i <= length; i++) {
			newArray[i] = arr[i-1];
		}
		arr = newArray;

	length++;
}

int Vector::deletePos(int position) {
	if(position >= 0 && position < length) {
		capacity--;
		bool b;
		int* newArray = new int[capacity];
		int i = 0;
		for (int i = 0; i < length; i++) {
		if(i == position) {
			b = true;
			continue;
		}
			b ? newArray[i - 1] = arr[i] : newArray[i] = arr[i];
		}
		arr = newArray;
		length--;
	}
}

int main() {
	Vector myVector;
	myVector.push(34);
	myVector.insertPos(2, 100);
	myVector.deletePos(2);
	myVector.display();
	return 0;
}

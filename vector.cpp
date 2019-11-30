#include <iostream>
#include <cstdlib>
using namespace std;

class Vector {
	private:
	int length;
	int capacity;
	int* arr;
	public:
	void insert(int value);
	void display();
	void insertAt(int index, int value);
	void deleteItem(int index);
	int get(int index);
	int indexOf(int value);
	void sort();
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

void Vector::insert(int value) {
	if(length == capacity) {
		capacity *= 2;
		int* newArray = new int[capacity];
		for(int i = 0; i < length; i++) {
			newArray[i] = arr[i];
		}
		newArray[length] = value;
		arr = newArray;
	}
	else {
		arr[length] = value;
	}
		length++;
}

void Vector::insertAt(int index, int value) {
	if(index < 0 || index >= length) return;
		capacity++;
		int* newArray = new int[capacity];
		int i = 0;
		for (int i = 0; i < index; i++) {
			newArray[i] = arr[i];
		}
		newArray[index] = value;
		for (i = index+1; i <= length; i++) {
			newArray[i] = arr[i-1];
		}
		arr = newArray;

	length++;
}

void Vector::deleteItem(int index) {
	if(index >= 0 && index < length) {
		capacity--;
		bool b;
		int* newArray = new int[capacity];
		int i = 0;
		for (int i = 0; i < length; i++) {
		if(i == index) {
			b = true;
			continue;
		}
			b ? newArray[i - 1] = arr[i] : newArray[i] = arr[i];
		}
		arr = newArray;
		length--;
	}
}

int Vector::get(int index) {
	if(index >= 0 && index < length) {
		return arr[index];
	}
	cout << "No value with index " << index << " in the array" << endl;
}

int Vector::indexOf(int value) {
	for(int i = 0; i < length; i++) {
		if(arr[i] == value) {
			return i;
		}
	}
	cout << value << " is not in array" << endl;
	return -1;
}

void Vector::sort() {
	for(int i = 0; i < length; i++) {
		int minind = i;
		for(int j = i + 1; j < length; j++) {
			if(arr[j] < arr[minind]) {
				minind = j;
			}
		}
		if(minind != i) {
			int temp = arr[minind];
			arr[minind] = arr[i];
			arr[i] = temp;
		}
	}
}



int main() {
	Vector myVector;   
	myVector.insert(67);
	return 0;
}

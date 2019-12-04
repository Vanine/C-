#include "vector.h"
#include <iostream>
using namespace std;

Vector::Vector(){
		length=0;
		capacity=1;
		arr = new int[capacity];
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
		if(length == capacity) {
            capacity *= 2;
            int* newArray = new int[capacity];
            int i = 0;
            for (i = 0; i < index; i++) {
                newArray[i] = arr[i];
            }
            newArray[index] = value;
            for (i = index+1; i <= length; i++) {
                newArray[i] = arr[i-1];
            }
            arr = newArray;
            }
		else {
            for(int j = length; j > index; j--) {   //0,1,2,3,4,5,6,7
                arr[j] = arr[j-1];                  //0,1,2,3,3,4,5,6,7
            }
            arr[index] = value;
		}
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

void Vector::display() {
	for(int i = 0; i < length; i++) {
		cout << arr[i] << endl;
	}
}

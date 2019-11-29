#include <iostream>
#include <cstdlib>
using namespace std;

class Queue
{
	int top;
	int* arr;
	int capacity;
	public:
	 Queue(int n = 10) {
		arr = new int[n];
		capacity = n;
		top = 0;
	 }
	 void enqueue(int newItem);
	 int dequeue();
	 int peek();
	 int sizew();
	 bool isEmpty();
	 bool isFull();
	 void display();
};

void Queue::enqueue(int newItem) {
	if (!isFull()) {
		int* newArray = new int[capacity];
		newArray[0] = newItem;
		for(int i = 0; i < top; i++) {
			newArray[i+1] = arr[i];
		}
		arr = newArray;
		top++;
	}
	return;
}

void Queue::display() {
	for(int i = 0; i < top; i++) {
		cout << arr[i] << endl;
	}
}

int Queue::dequeue() {
	if(!isEmpty()) {
	int temp = arr[0];
	int* newArray = new int[capacity];
		for(int i = 0; i < top-1; i++) {
			newArray[i] = arr[i+1];
		}
		top--;
		arr = newArray;
		return temp;
	}
	else return 0;
}

int Queue::peek() {
	if(!isEmpty()) {
		return arr[0];
	}
	else return 0;
}

int Queue::sizew() {
	return top;
}

bool Queue::isEmpty() {
	return (top == 0);
}

bool Queue::isFull() {
	return (top == capacity);
}

int main() {
	Queue myQueue(3);
	myQueue.enqueue(4);
	myQueue.enqueue(5);
	myQueue.enqueue(6);
	myQueue.display();
	myQueue.dequeue();
	myQueue.display();
	cout << myQueue.peek() << endl;
	cout << boolalpha << myQueue.isFull() << endl;
	return 0;
}




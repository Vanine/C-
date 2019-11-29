#include <iostream>
#include <cstdlib>
using namespace std;

class Stack {
 int* arr;
 int top;
 int capacity;
public:
Stack(int size = 10) {
arr = new int[size];
capacity = size;
top = 0;
}
int pop();
int peek();
bool isEmpty();
bool isFull();
void push(int);
int size();
};



bool Stack::isEmpty() {
	if(top == 0) {
		return true;
	}
	else return false;
}

bool Stack::isFull() {
	return (top == capacity);
}

int Stack::peek() {
	if (isEmpty()) {
		return 0;
	}
else {
	return arr[top-1];
	}
}

int Stack::pop() {
	if (isEmpty()) {
		return 0;
	}
	else {
		int last = arr[top-1];
		arr[top-1]= NULL ;
		top--;
		return last;
	}
}

void Stack::push(int newItem) {
	if (!isFull()) {
		arr[top] = newItem;
		top++;
	}
}

int Stack::size() {
	return top;
}
 int main()
 {
 Stack myStack(3);
 myStack.push(1);
 myStack.push(2);
 myStack.push(3);
 cout << boolalpha << myStack.isEmpty()<<endl;
 cout  << myStack.isFull()<<endl;
 cout << myStack.peek()<<endl;
 return 0;
 }

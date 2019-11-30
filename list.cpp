#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
	node* next;
	int data;
};

class List {

	public:
	List() {
		head = NULL;
		tail = NULL;
	}
	node* head;
	node* tail;
	void insertStart(int newValue);
	void insertEnd(int newValue);
	void deleteStart();
	void deleteEnd();
	void deletePos(int pos);
	void insertPos(int pos, int newValue);
	void display();
	void bubbleSort();
	void selectSort();
	void swapItems(node* node_1, node* node_2);
};

void List::insertStart(int newValue) {
	node* newNode = new node;
	newNode->data = newValue;
	if (head == NULL) {
		newNode->next = NULL;
		head = newNode;
		tail = newNode;
	}
	else {
		node* temp = head;
		newNode->next = temp;
		head = newNode;
	}
}

void List::insertEnd(int newValue) {
	node* newNode = new node;
	newNode->data = newValue;
	if (tail == NULL) {
		newNode->next = NULL;
		head = newNode;
		tail = newNode;
	}
	else {
		node* temp = tail;
		newNode->next = NULL;
		temp->next = newNode;
		tail = newNode;
	}
}

void List::deleteStart() {
	node* temp = new node;
	temp = head;
	head = head->next;
	delete temp;
}



void List::deleteEnd() {
node* prev = new node;
node* current = new node;
prev = head;
current = tail;
	while (prev->next != tail) {
		prev = prev->next;
	};
	prev->next = NULL;
	tail = prev;
	delete current;
}

void List::deletePos(int pos) {
	node* prev = new node;
	node* current = new node;
	prev = head;
	for (int i = 1; i < pos-1; i++) {
		prev = prev->next;
	}
	current = prev->next;
	prev->next = current->next;
	delete current;
}

void List::insertPos(int pos, int newValue) {
	node* prev = new node;
	node* newNode = new node;
	newNode->data = newValue;
	prev = head;
	for (int i = 1; i < pos-1; i++) {
		prev = prev->next;
	}
	newNode->next = prev->next;
	prev->next = newNode;
}

void List::display() {
	node* temp = new node;
	temp = head;
	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}

void List::swapItems(node* node_1, node* node_2) {
	int temp = node_1->data;
	node_1->data = node_2->data;
	node_2->data = temp;
}

void List::bubbleSort() {
	node* temp_1 = new node;
	node* temp_2 = new node;
	temp_1 = head;
	temp_2 = head;
	while(temp_1 != tail) {
		while(temp_2 != tail) {
			if (temp_2->next->data < temp_2->data) {
				swapItems(temp_2, temp_2->next);
			}
			temp_2 = temp_2->next;
		}
		temp_1 = temp_1->next;
		temp_2 = head;
	}
	return;
}

void List::selectSort() {
	node* temp_1 = new node;
	node* temp_2 = new node;
	node* minDataNode = new node;
	temp_1 = head;
	temp_2 = head->next;
	int minData = temp_1->data;
	while(temp_1 != tail) {
		minDataNode = temp_1;
		while(temp_2 != tail) {
			if(temp_2->data < minDataNode->data) {
				minDataNode = temp_2;
			}
			temp_2 = temp_2->next;
		}
		if(minDataNode != temp_1) {
			swapItems(minDataNode, temp_1);
		}
		temp_1 = temp_1->next;
		temp_2 = temp_1->next;
	}
}

int main() {
	List myList;
	myList.insertStart(1);
	myList.insertStart(34);
	myList.insertEnd(90);
	myList.insertEnd(45);
	myList.insertStart(3);
	myList.display();
	myList.selectSort();
	myList.display();
	return 0;
}


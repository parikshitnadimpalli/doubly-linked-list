#include <iostream>
#include <string>
#include <new>
#include <limits>

class Node 
{
	int data;
	Node *prev, *next;
public:
	Node(int);

	int getData() { return data; }
	void setData(int d) { data = d; }
	Node* getPrev() { return prev; }
	void setPrev(Node* p) { prev = p; }
	Node* getNext() { return next; }
	void setNext(Node* n) { next = n; }

	~Node();
};

int integerInput();
Node* newNode();
bool confirmation();
void clearScreen();
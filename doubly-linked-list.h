#include "node.h"

class DoublyLinkedList 
{
	int size;
	Node *head, *tail;
public:
	DoublyLinkedList();
	
	bool invalidInput(int i) { return (i > size) || (i <= 0); }
	int getSize() { return size; }
	Node* getNodeAt(int); // My code reduces the time complexity to n/2 from n just by adding a condition to check if the given index is beyond the half point or not
	void append(Node*);
	void prepend(Node*);
	void insertAfter(int, Node*);
	void deleteAt(int);
	void updateAt(int, int);
	void display();
};
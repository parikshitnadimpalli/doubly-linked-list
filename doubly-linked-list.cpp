#include "doubly-linked-list.h"
using namespace std;

DoublyLinkedList::DoublyLinkedList() 
{
	size = 0;
	head = tail = nullptr;
}

Node* DoublyLinkedList::getNodeAt(int i) 
{
	if (head == nullptr)
	{
		cout << endl << "The list is empty!" << endl;
		return nullptr;
	}
	if (invalidInput(i))
	{
		cout << endl << "The given index is invalid! Do you want to try again with correct index? Enter 'y' for yes and 'n' for no: ";

		if (confirmation())
			getNodeAt(integerInput());
		else
			return nullptr;
	}
	if (i == 1)
		return head;
	if (i == size)
		return tail;

	Node* trav;

	if (i > size / 2)
	{
		trav = tail->getPrev();
		for (int j = size - 1; j > i; j--) // Traversing the list in reverse starting from the node just before the tail
		{
			trav = trav->getPrev();
		}
	}
	else
	{
		trav = head->getNext();
		for (int j = 2; j < i; j++) // Traversing the list normally
		{
			trav = trav->getNext();
		}
	}

	return trav;
}

void DoublyLinkedList::append(Node* n)
{
	if (n == nullptr)
	{
		delete n;
		return;
	}	
	if (head == nullptr)
	{
		head = n;
		size++;
		cout << endl << "List was empty. Node successfully added at the head!" << endl;
		n = nullptr;
		delete n;
		return;
	}
	if (tail == nullptr)
	{
		head->setNext(n);
		n->setPrev(head);
		tail = n;
		size++;
		cout << endl << "List contained only one node. Node successfully appended!" << endl;
		n = nullptr;
		delete n;
		return;
	}
	
	tail->setNext(n);
	n->setPrev(tail);
	tail = n;
	size++;
	cout << endl << "Node successfully appended!" << endl;
	n = nullptr;
	delete n;
}

void DoublyLinkedList::prepend(Node* n)
{
	if (n == nullptr)
	{
		delete n;
		return;
	}
	if (head == nullptr)
	{
		append(n);
		n = nullptr;
		delete n;
		return;
	}
	if (tail == nullptr)
	{
		n->setNext(head);
		head->setPrev(n);
		tail = head;
		head = n;
		size++;
		cout << endl << "List contained only one Node. Node successfully prepended!" << endl;
		n = nullptr;
		delete n;
		return;
	}

	n->setNext(head);
	head->setPrev(n);
	head = n;
	size++;
	cout << endl << "Node successfully prepended!" << endl;
	n = nullptr;
	delete n;
}

void DoublyLinkedList::insertAfter(int i, Node* n)
{
	if (n == nullptr)
	{
		delete n;
		return;
	}
	if (head == nullptr || i == size)
	{
		append(n);
		n = nullptr;
		delete n;
		return;
	}

	Node* temp = getNodeAt(i);
	if (temp == nullptr)
	{
		delete temp;
		return;
	}

	n->setPrev(temp);
	n->setNext(temp->getNext());
	temp->setNext(n);
	n->getNext()->setPrev(n);
	size++;
	cout << endl << "Node successfully inserted after index: " << i << endl;
	temp = nullptr;
	delete temp;
}

void DoublyLinkedList::deleteAt(int i)
{
	cout << endl << "Are you sure you want to delete the node at index: " << i << "?" << endl;
	if (!confirmation)
		return;

	if (i == 1)
	{
		if (size == 1)
		{
			head = nullptr;
			size--;
			cout << endl << "Node successfully deleted!" << endl;
			return;
		}
		if (size == 2)
		{
			head = tail;
			tail = nullptr;
			size--;
			cout << endl << "Node successfully deleted!" << endl;
			return;
		}

		Node* temp = head;
		head = head->getNext();
		head->setPrev(nullptr);
		delete temp;
		size--;
		cout << endl << "Node successfully deleted!" << endl;
		return;
	}
	if (i == size)
	{
		if (size == 2)
		{
			tail = nullptr;
			cout << endl << "Node successfully deleted!" << endl;
			return;
		}

		Node* temp = tail;
		tail = tail->getPrev();
		tail->setNext(nullptr);
		delete temp;
		size--;
		cout << endl << "Node successfully deleted!" << endl;
		return;
	}

	Node* temp = getNodeAt(i);
	if (temp == nullptr)
	{
		delete temp;
		return;
	}

	temp->getPrev()->setNext(temp->getNext());
	temp->getNext()->setPrev(temp->getPrev());
	delete temp;
	size--;
	cout << endl << "Node successfully deleted!" << endl;
}

void DoublyLinkedList::updateAt(int i, int d)
{
	Node* temp = getNodeAt(i);
	if (temp == nullptr)
	{
		delete temp;
		return;
	}

	temp->setData(d);
	cout << endl << "Node successfully updated!" << endl;
	temp = nullptr;
	delete temp;
}

void DoublyLinkedList::display() 
{
	switch (size) 
	{
	case 0:
		cout << endl << "Empty list! No Nodes to display." << endl;
		return;
	case 1:
		cout << endl << head->getData() << endl;
		return;
	case 2:
		cout << endl << head->getData() << " -> " << tail->getData() << endl;
		return;
	default:
		break;
	}

	cout << endl;
	Node* trav = head;
	for (int i = 1; i <= size; i++) 
	{
		cout << trav->getData() << " <--> ";
		if (i % 18 == 0)
			cout << endl;
		trav = trav->getNext();
	}

	cout << endl;
	trav = nullptr;
	delete trav;
}
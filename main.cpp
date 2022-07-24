/*
AUTHOR	:	Parikshit N
TOPIC	:	Doubly Linked List
Version	:	1.0
*/
#include "doubly-linked-list.h"
using namespace std;

int main() 
{
	int option, i, d;
	string msg;
	DoublyLinkedList dll;

	do {

		cout << "\t\t\t|  Enter any one of the options below:      |" << endl;
		cout << "\t\t\t|                                           |" << endl;
		cout << "\t\t\t| NOTE: The list can only store integer     |" << endl;
		cout << "\t\t\t|       values. Index values start from 1   |" << endl;
		cout << "\t\t\t|                                           |" << endl;
		cout << "\t\t\t|             Press 0 to exit               |" << endl;
		cout << "\t\t\t|    1. Append a value to the list          |" << endl;
		cout << "\t\t\t|    2. Prepend a value to the list         |" << endl;
		cout << "\t\t\t|    3. Check if the list is empty          |" << endl;
		cout << "\t\t\t|    4. Get the value at an index           |" << endl;
		cout << "\t\t\t|    5. Insert a Node after an index        |" << endl;
		cout << "\t\t\t|    6. Count the total number of values    |" << endl;
		cout << "\t\t\t|    7. Delete the value at a position      |" << endl;
		cout << "\t\t\t|    8. Change the value at a position      |" << endl;
		cout << "\t\t\t|    9. Display the entire list             |" << endl;
		cout << "\t\t\t|   10. Clear screen                        |" << endl;
		cout << "\t\tEnter option: ";
		option = integerInput();

		switch (option) {

		case 0:
			break;
		case 1:
			dll.append(newNode());
			break;
		case 2:
			dll.prepend(newNode());
			break;
		case 3:
			msg = dll.getSize() == 0 ? "The list is empty." : "The list is not empty.";
			cout << endl << msg << endl;
			break;
		case 4:
			cout << endl << "Enter the index of the Node: ";
			i = integerInput();
			cout << "The data at index " << i << " is: " << dll.getNodeAt(i)->getData() << endl;
			break;
		case 5:
			cout << endl << "Enter the index to insert after: ";
			i = integerInput();
			dll.insertAfter(i, newNode());
			break;
		case 6:
			cout << endl << "The total number of nodes in the list are: " << dll.getSize() << endl;
			break;
		case 7:
			cout << endl << "Enter the index of the Node that you want to delete: ";
			dll.deleteAt(integerInput());
			break;
		case 8:
			cout << endl << "Enter the index where you want to change the value: ";
			i = integerInput();
			cout << "Enter the new integer data: ";
			dll.updateAt(i, integerInput());
			break;
		case 9:
			dll.display();
			break;
		case 10:
			clearScreen();
			break;
		default:
			cout << endl << "Invalid option!";
			break;
		}
	} while (option != 0);

    return 0;
}
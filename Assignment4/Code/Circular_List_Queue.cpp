//Code written by Professor Ross. Modified by Quinn Roemer
#include <iostream>
using namespace std;

//The List
#define SIZE 10
char myList[SIZE];
int head, tail, used;

//Function Declarations.
void q(char);
void traverse(void);
bool isEmpty(void);
char dq(void);

//Main function to execute.
void main(void)
{
	//Intilization.
	head = tail = used = 0;
	cout << "Queueing A, B, C in that order:" << endl;
	q('A');
	q('B');
	q('C');
	traverse();
	cout << "Removed " << dq() << endl;
	traverse();
	cout << "Queueing C, D, E, F in that order:" << endl;
	q('C');
	q('D');
	q('E');
	q('F');
	traverse();
	cout << "Queueing 5 X's" << endl;
	q('X');
	q('X');
	q('X');
	q('X');
	q('X');
	traverse();
	cout << "Removed " << dq() << endl;
	cout << "Removed " << dq() << endl;
	cout << "Removed " << dq() << endl;
	cout << "Removed " << dq() << endl;
	traverse();
	//Empty the list.
	cout << "Removed ";
	while (!isEmpty())
	{
		cout << dq() << ", ";
	}
	cout << endl;
	traverse();
}

//Receives a data element and appends it to the tail of the list.
void q(char d)
{
	//If list is empty.
	if (!used)
	{
		myList[head] = d;
		used++;
		return;
	}

	//Prevent Overflow.
	if ((head + 1) % SIZE == tail)
	{
		cout << "Overflow. Element not appended.\n";
		return;
	}

	//Append data.
	head = (head + 1) % SIZE;
	myList[head] = d;
	used++;
}

//Traverses the list from the head to the tail and prints out each data element.
void traverse(void)
{
	//Pointer
	char p;

	//Empty list
	if (isEmpty())
	{
		cout << "The list is empty.\n";
		return;
	}

	//1 element.
	if (used == 1)
	{
		cout << "The list contains: " << myList[head] << endl;
		return;
	}

	//More than 1 element.
	p = tail;
	cout << "The list contains: \n";
	do
	{
		cout << myList[p];
		p = (p + 1) % SIZE;
	} while (p != (head + 1) % SIZE);

	cout << endl;
}

//Returns true if the list is empty, returns false otherwise.
bool isEmpty(void)
{
	if (!used)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Returns the head element and removes it from the list. Returns -1 if empty.
char dq(void)
{
	char p = tail;
	char temp = myList[tail];

	if (isEmpty())
	{
		return -1;
	}

	if (used == 1)
	{
		used--;
		return temp;
	}

	while (p != head)
	{
		myList[p] = myList[p + 1];
		p++;
	}

	head--;
	used--;
	return temp;

}
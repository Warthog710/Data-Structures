#include <iostream>

using namespace std;

//The List
#define SIZE 10
char myList[SIZE];
int head, tail, used;

//Function Declarations.
void push(char);
void traverse(void);
int isEmpty(void);
char pop(void);
char peek(void);

//Main function to execute.
void main(void)
{
	//Intilization.
	head = tail = used = 0;
	cout << "Pushing A, B, C, D, E, F in that order:" << endl;
	push('A');
	push('B');
	push('C');
	push('D');
	push('E');
	push('F');
	traverse();
	cout << "Pushing 5 X's in that order:" << endl;
	push('X');
	push('X');
	push('X');
	push('X');
	push('X');
	traverse();
	cout << "Removed " << pop() << endl;
	cout << "Removed " << pop() << endl;
	cout << "Removed " << pop() << endl;
	cout << "Removed " << pop() << endl;
	cout << "Peeking: " << peek() << endl;
	traverse();
	cout << "Removed " << pop() << endl;
	cout << "Removed " << pop() << endl;
	traverse();
	//Empty the list.
	cout << "Removed ";
	while (!isEmpty())
	{
		cout << pop() << ", ";
	}
	cout << endl;
	traverse();
	cout << "Peek: " << peek();
}

//Receives a data element and appends it to the head of the list.
void push(char d)
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
	p = head;
	cout << "The list contains: \n";
	do
	{
		cout << myList[p];
		p = (p - 1) % SIZE;
	} while (p != (tail - 1) % SIZE);

	cout << endl;
}

//Returns true if the list is empty, returns false otherwise.
int isEmpty(void)
{
	if (used)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//Retruns the top item on the stack and deletes it. Returns -1 if empty.
char pop(void)
{
	if (isEmpty())
	{
		return -1;
	}

	char temp = myList[head];
	head--;
	used--;
	return temp;
}

//Returns the top item on the stack. Returns -1 if empty.
char peek(void)
{
	if (isEmpty())
	{
		return -1;
	}
	else
	{
		return myList[head];
	}
}
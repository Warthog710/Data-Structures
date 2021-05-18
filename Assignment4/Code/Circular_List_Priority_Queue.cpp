#include <iostream>

using namespace std;

//The List
#define SIZE 10
char myList[SIZE];
int head, tail, used;

//Function Declarations.
void insert(char);
void traverse(void);
bool isEmpty(void);
char dq(void);
char peek(void);

//Main function to execute.
void main(void)
{
	//Intilization.
	head = tail = used = 0;
	cout << "Queueing B, C, A in that order:" << endl;
	insert('B');
	insert('C');
	insert('A');
	traverse();
	cout << "Removed " << dq() << endl;
	traverse();
	cout << "Queueing F, C, E, D in that order:" << endl;
	insert('F');
	insert('C');
	insert('E');
	insert('D');
	traverse();
	cout << "Queueing 5 X's" << endl;
	insert('X');
	insert('X');
	insert('X');
	insert('X');
	insert('X');
	cout << "Peek: " << peek() << endl;
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
	cout << "Peek: " << peek() << endl;
}

//Receives a data element and appends it to the tail of the list.
void insert(char d)
{
	char temp;

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

	//Sort data
	for (int i = 0; i < head; i++)
	{
		for (int j = 0; j < head; j++)
		{
			if (myList[j] >= myList[j + 1])
			{
				temp = myList[j + 1];
				myList[j + 1] = myList[j];
				myList[j] = temp;
			}
		}
	}
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

//Returns the tail element and returns it. Returns -1 if empty.
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

//Returns the tail element.
char peek(void)
{
	if (isEmpty())
	{
		return -1;
	}

	else
	{
		return myList[tail];
	}
}
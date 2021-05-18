//Code written by Professor Ross. Modified by Quinn Roemer
#include <iostream>
using namespace std;

//Our node.
struct node {
	node* next;
	char d;
};

//Head and tail pointers.
node* head = 0;
node* tail = 0;

//Function declarations.
char pop(void);
void push(char);
void traverse(void);
bool isEmpty(void);
char peek(void);

//Main function to execute.
void main(void)
{
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
	cout << "Removed " << pop() << endl;
	cout << "Peek: " << peek() << endl;
	traverse();
	cout << "Removed " << pop() << endl;
	cout << "Removed " << pop() << endl;
	traverse();
	//Empty the list.
	cout << "Removed ";
	while (isEmpty())
	{
		cout << pop() << ", ";
	}
	cout << endl;
	traverse();
	cout << "Peek: " << peek() << endl;
}

//Recieves a char element and appends it to the head of the list.
void push(char d)
{
	//Make a new node.
	node* p = new node;
	p->next = 0;
	p->d = d;

	//List is empty.
	if (!head)
	{
		head = tail = p;
	}

	//Append to the head end.
	else
	{
		p->next = head;
		head = p;
	}
}

//Traverses the list from the head to the tail, and prints out each char element.
void traverse(void)
{
	node* p = head;

	cout << "The list contains: ";
	while (p)
	{
		cout << p->d << " ";
		p = p->next;
	}
	cout << endl;
}

//Returns true if the list is empty, returns false otherwise.
bool isEmpty(void)
{
	if (!head)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//Removes a char element from the head of the list and returns it.
//Returns -1 if the list is empty.
char pop(void)
{
	node* p;
	char temp;

	//Return null of the list is empty.
	if (!head)
	{
		return -1;
	}

	//One node.
	if (head == tail)
	{
		//Remove and destroy head node.
		temp = head->d;
		delete head;
		head = tail = 0;
		return temp;
	}

	//More than one node. Remove and destroy head node.
	p = head;
	head = head->next;
	temp = p->d;
	delete p;
	return temp;
}

//Returns the head element. Returns -1 if empty.
char peek(void)
{
	//List is empty.
	if (!head)
	{
		return -1;
	}

	else
	{
		return head->d;
	}
}
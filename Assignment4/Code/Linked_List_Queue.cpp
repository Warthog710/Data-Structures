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
char dq(void);
void q(char);
void traverse(void);
bool isEmpty(void);

//Main function to execute.
void main(void)
{
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
	while (isEmpty())
	{
		cout << dq() << ", ";
	}
	cout << endl;
	traverse();
}

//Recieves a char element and appends it to the tail of the list.
void q(char d)
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

	//Append to the tail end.
	else
	{
		tail->next = p;
		tail = p;
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
char dq(void)
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
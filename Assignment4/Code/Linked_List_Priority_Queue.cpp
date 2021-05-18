//Code written by Professor Ross. Modified by Quinn Roemer.
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
void traverse(void);
bool isEmpty(void);
char peek(void);
void insert(char);

//Main function to execute.
void main(void)
{
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
	while (isEmpty())
	{
		cout << dq() << ", ";
	}
	cout << endl;
	traverse();
	cout << "Peek: " << peek() << endl;
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

//Returns a char element from the list.
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

//Inserts an element into the list in a greater to less fashion.
void insert(char d)
{
	node* c;
	node* pc;

	//Create a new node.
	node* p = new node;
	p->d = d;

	//List is empty.
	if (!head)
	{
		head = tail = p;
		p->next = 0;
		return;
	}
	//One node.
	if (head == tail)
	{
		if (p->d >= head->d)
		{
			p->next = head;
			head = p;
			return;
		}
		else
		{
			head->next = p;
			p->next = 0;
			tail = p;
			return;
		}
	}
	//Two or more nodes.
	pc = head;
	c = head->next;

	//Found at the head.
	if (pc->d <= p->d)
	{
		p->next = head;
		head = p;
		return;
	}
	//Look at nodes after the head node.
	while (c)
	{
		//Place at tail node.
		if (c == tail)
		{
			tail->next = p;
			tail = p;
			tail->next = 0;
			return;
		}
		if (c->d <= p->d)
		{
			pc->next = p;
			p->next = c;
			return;
		}
		pc = c;
		c = c->next;
	}
	return;
}
//Code written by Professor Ross. Modified by Quinn Roemer.
#include <iostream>
using namespace std;

//Our node.
struct node {
	node* previous;
	node* next;
	char d;
};

//Head and tail pointers.
node* head = 0;
node* tail = 0;

//Function declarations.
char removeTail(void);
char removeHead(void);
void appendTail(char);
void appendHead(char);
void traverseFWD(void);
void traverseBWD(void);
int isEmpty(void);

//Main function to execute.
void main(void)
{
	appendTail('A');
	appendHead('B');
	appendHead('C');
	appendHead('D');
	appendTail('E');
	appendTail('F');
	cout << "Forwards: ";
	traverseFWD();
	cout << "Backwards: ";
	traverseBWD();
	cout << "Removed: " << removeTail() << endl;
	cout << "Removed: " << removeHead() << endl;
	cout << "Forwards: ";
	traverseFWD();
	cout << "Backwards: ";
	traverseBWD();

	//Empty the list.
	cout << "Removed: ";
	while (!isEmpty())
	{
		cout << removeTail() << ", ";
	}
	cout << endl;
	cout << "Forwards: ";
	traverseFWD();
	cout << "Backwards: ";
	traverseBWD();
}
//Recieves a char element and appends it to the tail of the list.
void appendTail(char d)
{
	//Make a new node.
	node* p = new node;
	p->previous = 0;
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
		p->previous = tail;
		tail = p;
	}
}
//Recieves a char element and appends it to the head of the list.
void appendHead(char d)
{
	//Make a new node.
	node* p = new node;
	p->previous = 0;
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
		head->previous = p;
		p->next = head;
		head = p;
	}
}
//Traverses the list from the head to the tail, and prints out each char element.
void traverseFWD(void)
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
//Traverses the list from the tail to the head, and prints out each char element.
void traverseBWD(void)
{
	node* p = tail;
	cout << "The list contains: ";
	while (p)
	{
		cout << p->d << " ";
		p = p->previous;
	}
	cout << endl;
}
//Returns true if the list is empty, returns false otherwise.
int isEmpty(void)
{
	if (head)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//Removes a char element from the head of the list and returns it.
//Returns -1 if the list is empty.
char removeHead(void)
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
	head->previous = 0;
	temp = p->d;
	delete p;
	return temp;
}
//Removes a char element from the tail of the list and returns it.
//Returns -1 if the list is empty.
char removeTail(void)
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
		//Remove and destroy tail node.
		temp = head->d;
		delete head;
		head = tail = 0;
		return temp;
	}
	//More than one node. Remove and destroy tail node.
	p = tail;
	tail = tail->previous;
	tail->next = 0;
	temp = p->d;
	delete p;
	return temp;
}
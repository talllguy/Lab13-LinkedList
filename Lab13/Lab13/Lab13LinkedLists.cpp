/************************************************************
COSC 501
Elliott Plack
19 NOV 2013                                   Due 25 NOV 2013
Problem: Create a 1-dimensional array with n elements; get
the size of the array as user input (validate!), max size
should be 10 (declared as class constant). Perform a
variety of functions with the array.
Algorithm: Get array size from user, validate, get values,
perform functions.
************************************************************/

#include <iostream>
using namespace std;



int main()
{
char runQuestion = 'Y';
int i;

cout << "Do you want to start(Y/N): ";
cin >> runQuestion;

while (runQuestion == 'Y' || runQuestion == 'y')
{
	// declare array with pointers
	struct node
	{
		double data;
		node *next;
	};

	node *q, *head;
	head = new node;
	head->data = 0;
	head->next = NULL;
	node *p;
	p = head;

	cin >> i;
	while (i != -1)
	{
		q = new node;
		q->data = i;
		head->data++;
		q->next = NULL;
		p->next = q;
		p = q;
		cin >> i;
	}

	// print
	cout << "The node elements are:\n";

	p = head->next;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}

	node *t = new node;
	t->data = 25;
	t->next = q->next;
	q->next = t;

	p = head->next;
	if (p != NULL && p->data <=25)
	{
		cout << p->data << endl;
		p = p->next;
	}
	else if (p != NULL)
	{

	}
	

	cout << "Do you want to continue(Y/N): ";
	cin >> runQuestion;
	}



	return 0;
}

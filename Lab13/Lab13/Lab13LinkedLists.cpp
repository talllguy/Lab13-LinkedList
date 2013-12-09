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

struct node
{
	int data;
	node *next;
};

int main()
{
char runQuestion = 'Y';

cout << "Do you want to start(Y/N): ";
cin >> runQuestion;

while (runQuestion == 'Y' || runQuestion == 'y')
{
	
	node *head = NULL; // set up header null to first pointer
	
	node *pointerP, *pointerQ; // pointers

	cout << "Please enter 10 numbers, in numerical order, below:\n";
	
	for (int i = 0; i < 10; i++)
	{
		// Reserve space for new node and fill it with data 
		pointerP = new node;
		cout << (i + 1) << ". "; // 1. , 2. etc
		cin >> pointerP->data; // validate (see #2)
		pointerP->next = NULL;

		// Set up link to this node 
		if (head == NULL)
			head = pointerP;
		else
		{
			pointerQ = head; // We know this is not NULL - list not empty! 
			while (pointerQ->next != NULL)
				pointerQ = pointerQ->next; // Move to next link in chain 
			pointerQ->next = pointerP;
		}
	}

	// print
	cout << "The node elements are:\n";

	pointerP = head;
	while (pointerP != NULL)
	{
		cout << pointerP->data << endl;
		pointerP = pointerP->next;
	}


	// add a number

	pointerP = head;
	pointerQ = head;

	int newNumber = 0;

	cout << "Enter a number to insert: ";
	cin >> newNumber;
	


	while (pointerP->data < newNumber)
	{
		pointerQ = pointerP;
		pointerP = pointerP->next;
	}
	node *pointerT = new node;
	pointerT->data = newNumber;
	pointerT->next = pointerQ->next;
	pointerQ->next = pointerT;

	cout << "The node elements are:\n";

	pointerP = head;
	while (pointerP != NULL)
	{
		cout << pointerP->data << endl;
		pointerP = pointerP->next;
	}

	// delete a node

	int deleteMe = 0;
	bool flag = true;

	cout << "Enter a number in the list to delete: ";
	cin >> deleteMe;

	pointerQ = head;
	pointerP = pointerQ->next;
	flag = true;
	do {
		if (pointerP->data == deleteMe)
		{
			pointerQ->next = pointerP->next;
			delete pointerP;
			flag = false;
		}
		else
		{
			pointerQ = pointerP;
			pointerP = pointerP->next;
		}
	} while (flag && (pointerP->next != NULL));

	// print
	pointerP = head;
	while (pointerP != NULL)
	{
		cout << pointerP->data << endl;
		pointerP = pointerP->next;
	}

	cout << "Do you want to continue(Y/N): ";
	cin >> runQuestion;
	}



	return 0;
}

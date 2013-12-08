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

	node *head = NULL; // set up header null to first pointer
	
	node *pointerP, *pointerQ; // pointers
	
	for (int i = 0; i < 10; i++)
	{
		// Reserve space for new node and fill it with data 
		pointerP = new node;
		cout << "Please enter a number: ";
		cin >> pointerP->data;
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

	// set up another node to add
	//node *pointerT = new node;
	//pointerT->data = 25; // change to cin
	//pointerT->next = pointerQ->next;
	//pointerQ->next = pointerT;

	//pointerP = head->next;
	//if (pointerP != NULL && p->data <=25)
	//{
	//	cout << p->data << endl;
	//	pointerP = p->next;
	//}
	//else if (pointerP != NULL)
	//{

	//}
	//

	cout << "Do you want to continue(Y/N): ";
	cin >> runQuestion;
	}



	return 0;
}

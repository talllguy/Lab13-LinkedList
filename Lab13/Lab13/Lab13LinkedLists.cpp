/************************************************************
COSC 501
Elliott Plack
04 DEC 2013                                 Due 09 DEC 2013
Problem: Read in a sorted list of 10 numbers and store them
	in a linked list
Algorithm: Read in numbers using pointers. Then insert and
	delete using pointers.
************************************************************/

#include <iostream>
using namespace std;

struct node  // set up node structure
{
	int data;
	node *next;
};

int main()
{
	char runQuestion = 'Y'; // check if the user wants to restart

	while (runQuestion == 'Y' || runQuestion == 'y')
	{
		node *head = NULL; // set up header null to first pointer
		node *pointerP, *pointerQ; // pointers to initialize

		cout << "Please enter 10 numbers, in numerical order, below:\n";
	
		for (int i = 0; i < 10; i++)
		{
			// Reserve space for new node and fill it with data 
			pointerP = new node;
			cout << (i + 1) << ": "; // 1: , 2: etc
		
			while (!(cin >> pointerP->data)) // Get the input and validate it
			{
				cin.clear();     // Clear the error flags
				cin.ignore(100, '\n');    // Remove unwanted characters from buffer
				cout << "\aError! Reenter " << (i+1) << ": ";   // Re-issue the prompt
			}
		
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

		// add a number

		// move pointers to the beginning
		pointerP = head;
		pointerQ = head;

		int newNumber = 0; // set up new number variable

		cout << "Enter a number to insert: ";
		while (!(cin >> newNumber)) // Get the input and validate it
		{
			cin.clear();     // Clear the error flags
			cin.ignore(100, '\n');    // Remove unwanted characters from buffer
			cout << "\aError! Reenter a number to insert: ";   // Re-issue the prompt
		}
	
		while (pointerP->data < newNumber) // while the P is less than input
		{
			pointerQ = pointerP; // set q = p so the previous location is known
			pointerP = pointerP->next; // set P to go next
		}
		node *pointerT = new node; // new node to instert
		pointerT->data = newNumber; 
		pointerT->next = pointerQ->next; // since q didn't advance, it will be inserted
		pointerQ->next = pointerT;

		// delete a node

		int deleteMe = 0;
		bool flag = true;

		cout << "Enter a number in the list to delete: ";
		while (!(cin >> deleteMe)) // Get the input and validate it
		{
			cin.clear();     // Clear the error flags
			cin.ignore(100, '\n');    // Remove unwanted characters from buffer
			cout << "\aError! Reenter a number in the list to delete: ";   // Re-issue the prompt
		}
	
		pointerQ = head; // set up q to begining
		pointerP = pointerQ->next; // p becomes the next node after beginning
		flag = true; // set up flag bool
		do {
			if (pointerP->data == deleteMe)
			{
				pointerQ->next = pointerP->next; // advance
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
		while (pointerP != NULL) // not at the end of lis
		{
			cout << pointerP->data << endl; // output the lest
			pointerP = pointerP->next;
		}

		cout << "Do you want to restart? (Y/N): ";
		cin >> runQuestion;
		}

	return 0;
}

/*
 * Kristina Kolibab
 * 7/30/18
 * Just playing around with nodes and structs
 * Wanted to implement the 'last man' problem using
 * a circularly linked list
 *
 * Compile: g++ nodes.cpp -std=c++11
 * Execute: ./a.exe
 */

#include <iostream>

using namespace std;

struct Node 
{
	int data;
	struct Node *next;
};

Node *newNode(int d)
{
	Node *node = new Node;
	node->data = d;
	node->next = NULL;
	return node;
}

int lastMan(int size)
{
	if((size == 1) || (size == 2)) return 1;

	// Create a circularly linked list
	Node *head = newNode(1);
	Node *prev = head;
	for(int i = 2; i <= size; i++)
	{
		prev->next = newNode(i);
		prev = prev->next;
	}	
	prev->next = head;
	
	// Start killing
	Node *ptr1 = head, *ptr2 = head;
	while(ptr1->next != ptr1)
	{
		ptr2 = ptr2->next->next; // skip over node to be killed
		ptr1->next = ptr2; // ptr1's next skips one, now points at ptr2's location
		ptr1 = ptr1->next; // step forward
	}

	return ptr1->data;
}

int main(int argc, char ** argv){

	cout << "last man 5: " << lastMan(5) << endl; 
	cout << "last man 10: " << lastMan(10) << endl;
	cout << "last man 100: " << lastMan(100) << endl;

	return 0;
}

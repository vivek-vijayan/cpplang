#include <iostream>
#include <stack>

// a->b->c-> d
//

struct LinkList
{
	int data;
	struct LinkList *next;
	LinkList(int value) { data = value; }
};

LinkList *reverse(LinkList *head)
{
	LinkList *next = NULL, *previous = NULL;
	while (head!= NULL)
	{
		next = head -> next;
		head -> next = previous;
		previous = head;
		head = next;
	} 
	head = previous;
	return head;
}

int main()
{
	LinkList *a = new LinkList(10);
	LinkList *b = new LinkList(20);
	LinkList *c = new LinkList(30);
	LinkList *d = new LinkList(40);

	// Linking the list
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = NULL;

	LinkList *head = a;

	do
	{
		std::cout << head->data << " -> ";
		head = head->next;
	} while (head != NULL);
	std::cout << "NULL\n";
	head = reverse(a);
	
	// LinkList *head = a;

	std::cout << "\n\nAfter reversing \n ";
	do
	{
		std::cout << head->data << " -> ";
		head = head->next;
	} while (head != NULL);
	std::cout << "NULL\n";
	return 0;
}

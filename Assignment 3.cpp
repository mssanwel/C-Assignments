#include <iostream>

using namespace std;

struct Node
{
	int info;
	Node * next;
};

void print_list(Node * head)
{
    //int counter=0;
    //Node * current = head;
	//while (counter != n)
	{
	    cout << head->info;
		// process the current node, e.g., print the content
		//cout << current->info;
		//current = current->next;
		//counter++;
	}
}

void tail_insert(Node * & head, Node * & tail, int num)
{
	Node * p = new Node;
	p->info = num;
	p->next = NULL;

	if (head == NULL) {
		head = p;
		tail = p;
	}
	else {
		tail->next = p;
		tail = p;
	}
}

void circularList(int n, Node* &head, Node* &tail)
{
    int counter=1;
    while ( counter <= n )
    {
        tail_insert(head, tail, counter);
        counter++;
    }
    (*tail).next=head;
}
int transverse(Node* &head, int k)
{
    int counter=0;
    Node *prev= NULL, *prev2=NULL;

	while (counter != k)
    {
        prev2=prev;
        prev=head;
        head = head->next;
        counter++;
	}
    if (head->next == head)
        return 0;
    prev2->next=prev->next;
    delete prev;
    return 1;
}

int main()
{
    Node * head = NULL, * tail = NULL;
    int n = 0, k=0;

    // build circular linked list
    cin >> n;
    circularList(n, head, tail);
    //Use K transverse and delete
    cin>>k;
    while (transverse(head, k));

    // print the items in the linked list
    print_list(head);

    return 0;
}

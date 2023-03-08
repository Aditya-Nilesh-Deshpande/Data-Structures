#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next; //self referencing structure
};

struct node *head, *tail;

void Doubly_Linkedlist_Traversal(struct node *head)
{
    //  tail=head;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
void Doubly_Linkedlist_DeleteAtend()
{

    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }


    p->prev->next = NULL;
    p= p->prev;
    // while (head->next != NULL)
    // {
    //     head = head->next;
    // }
    // head->prev->next = NULL;
    // head = head->prev;
}

void Doubly_Linkedlist_DeleteAtfirst()
{
    struct node *temp; //Keeps track of first node

    temp = head;
    head = head->next; //Moving  head to next node
    head->prev = NULL;
    delete temp;
}


void Doubly_Linkedlist_DeleteAtpos()
{
    struct node *temp = head; //Keeps track of first node
    int pos;
    cout << "Enter the position\n";
    cin >> pos;

    int i = 1;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

int main()
{
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    head = new struct node;
    second = new struct node;
    third = new struct node;
    fourth = new struct node;
    fifth = new struct node;

    head->data = 7; // head->pointer for current node
    head->next = second;
    head->prev=NULL;

    second->data = 10;
    second->next = third;
    second->prev=head;

    third->data = 15;
    third->next = fourth;
    third->prev=second;


    fourth->data = 66;
    fourth->next = fifth;
    fourth->prev=third;

    fifth->data = 84;
    fifth->next = NULL;
    fifth->prev=fourth;


    cout << "Doubly Linked list is \n";
    Doubly_Linkedlist_Traversal(head);

    // cout<<"\nDoubly linked list after deletion\n";
    // Doubly_Linkedlist_DeleteAtfirst();
    // Doubly_Linkedlist_Traversal(head);

    cout << "\nDoubly linked list after deletion\n";
    Doubly_Linkedlist_DeleteAtend();
    Doubly_Linkedlist_Traversal(head);

    // Doubly_Linkedlist_DeleteAtpos();
    // cout<<"\nDoubly linked list after deletion\n";
    // Doubly_Linkedlist_Traversal(head);
}
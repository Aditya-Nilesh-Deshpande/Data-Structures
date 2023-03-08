#include<iostream>
using namespace std;

struct node{
    int data;
    struct node*prev;
    struct node * next;   //self referencing structure

};

struct node* head,*tail;


void Doubly_Linkedlist_Traversal(struct node* ptr){
     tail=head;
     while(ptr!=NULL){
         cout<<ptr->data<<" ";
         ptr=ptr->next;
     }
     while(tail->next!=NULL){
         tail=tail->next;
     }
     

 }

 void Doubly_Linkedlist_insertAtBeg(){
     struct node* ptr=new struct node;
     cout<<"Enter the data\n";
     cin>>ptr->data;

     ptr->prev=tail;
     tail->next=ptr;
     tail=ptr;

 }

 void Doubly_Linkedlist_insertAtend(){
     struct node* ptr=new struct node;
     cout<<"Enter the data\n";
     cin>>ptr->data;

     ptr->next=NULL;
     ptr->prev=tail;
     tail->next=ptr;
     tail=ptr;

 }


 void Doubly_Linkedlist_insertAtindex(){
     struct node* temp=head;
     int i=0; 
     int pos;
     cout<<"Enter the position\n";
     cin>>pos;

     struct node* ptr=new struct node;
     cout<<"Enter the data\n";
     cin>>ptr->data;
    
     while(i<pos-1){
         temp=temp->next;
         i++;
     }

     ptr->next=temp->next;
     (temp->next)->prev=ptr;
     ptr->prev=temp;
     temp->next=ptr;


 }

 

 int main(){
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    head= new struct node;
    second= new struct node;
    third= new struct node;
    fourth= new struct node;
    fifth= new struct node;

    head->data=7;    // head->pointer for current node
    head->next=second;

    second->data=10;
    second->next=third;

    third->data=15;
    third->next=fourth;

    fourth->data=66;
    fourth->next=fifth;

    fifth->data=84;
    fifth->next=NULL;
    
    cout<<"Doubly Linked list is \n";
    Doubly_Linkedlist_Traversal(head);


    // cout<<"\nDoubly linked list after insertion is\n";
    // Doubly_Linkedlist_insertAtBeg();
    // Doubly_Linkedlist_Traversal(head);

    // cout<<"\nDoubly linked list after insertion is\n";
    // Doubly_Linkedlist_insertAtend();
    // Doubly_Linkedlist_Traversal(head);

    cout<<"\nDoubly linked list after insertion is\n";
    Doubly_Linkedlist_insertAtindex();
    Doubly_Linkedlist_Traversal(head);

 return 0;
    
 }
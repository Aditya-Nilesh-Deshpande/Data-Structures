#include<iostream>
using namespace std;

struct node{
    int data;
    struct node*prev;
    struct node * next;   //self referencing structure

};

struct node* head;

void Doubly_Linkedlist_creation(){
    struct  node* newnode,*temp;
    temp=head;
    head=NULL;
    int choice;

    while(choice){
        newnode=new struct node;
        cout<<"Enter the data\n";
        cin>>newnode->data;
        newnode->next=NULL;
        newnode->prev=NULL;

        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;

        }

        cout<<"Enter your choice\n";
        cin>>choice;

    }
}
void Doubly_Linkedlist_Traversal(struct node* ptr){
     
     while(ptr!=NULL){
         cout<<ptr->data<<" ";
         ptr=ptr->next;
     }

 }

 int main(){
    
    Doubly_Linkedlist_creation();
    cout<<"Doubly Linked list is \n";
    Doubly_Linkedlist_Traversal(head);
    
 }
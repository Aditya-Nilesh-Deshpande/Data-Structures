#include<iostream>
using namespace std;

struct node{
    int data;
    struct node * next;   //self referencing structure

};
 
void Linkedlist_Traversal(struct node* ptr){
     
     while(ptr!=NULL){
         cout<<ptr->data<<" ";
         ptr=ptr->next;
     }

 }

 struct node* Delete_AtFirst(struct node* head){
        struct node* ptr=head;
        head=head->next;   //moving head ahead 
        delete ptr;        //releasing ptr i.e first node
        return head;
 }


 struct node* Delete_AtIndex(struct node* head,int index){
        struct node* p=head;
        struct node*q =head->next;

    
        for(int i=0;i<index-1;i++){
            p=p->next;
            q=q->next;
        }

        p->next=q->next;
        delete q;
        return head;
 }


struct node* Delete_AtLast(struct node* head){
        struct node* p=head;
        struct node*q =head->next;


        while(q->next!=NULL){
            p=p->next;
            q=q->next; 
        }
        p->next=NULL;
        delete q;
        return head;
 }

 struct node* Delete_AtValue(struct node* head,int value){
        struct node* p=head;
        struct node*q =head->next;

    
        while(q->data!= value && q->next!=NULL){
            p=p->next;
            q=q->next;
        }
        
        if(q->data==value){
        p->next=q->next;
        delete q;
        } 
        return head;
 }


 int main(){
    struct node *head;
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

    cout<<"Linked list before deletion\n";
    Linkedlist_Traversal(head);

    // cout<<"\nLinked list after deletion\n";
    // head=Delete_AtFirst(head);
    // Linkedlist_Traversal(head);
    
    // cout<<"\nLinked list after deletion\n";
    // head=Delete_AtIndex(head,2);
    // Linkedlist_Traversal(head);


    // cout<<"\nLinked list after deletion\n";
    // head=Delete_AtLast(head);
    // Linkedlist_Traversal(head);


    cout<<"\nLinked list after deletion\n";
    head=Delete_AtValue(head,10);
    Linkedlist_Traversal(head);

    

 }
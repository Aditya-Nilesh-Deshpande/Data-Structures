#include<iostream>
using namespace std;

struct node{
    int data;
    struct node * next;   //self referencing structure

};
struct node *head;

void Linkedlisttraversal(struct node *ptr){
    while(ptr!=NULL){
      cout<<ptr->data<<" ";
      ptr=ptr->next;
    }
}

void linkedlist_reversal(){
    struct node*nextnode=head;
    struct node*currentnode=head;
    struct node*prevnode=NULL;


    while(nextnode!=NULL){
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;     //Updating head to last node
    
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
    
    
    Linkedlisttraversal(head);


    cout<<endl;
    cout<<"Linked list after reversal\n";
    linkedlist_reversal();
    Linkedlisttraversal(head);


return 0;

}

#include<iostream>
using namespace std;


class node{
    int data;
    node* next;
public:

    void traversal();
    void create();

};

node* head;

void node::create(){
     node *newnode,*temp;

     temp=head;
     int choice=1;

    while(choice){
       newnode=new node;           //Making a new node
       cout<<"Enter the data\n";
       cin>>newnode->data;
       newnode->next=NULL;
       
       if(head==NULL){
           head=newnode;
           temp=newnode;
       }

       else{
           temp->next=newnode;
           temp=newnode;
       }

       cout<<"Enter your choice\n";
       cin>>choice;

     }
}


void node::traversal(){
    node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main(){
    node temp;
    temp.create();
    temp.traversal();
 
    return 0;
}
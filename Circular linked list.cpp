#include<iostream>
using namespace std;


struct node{
    int data;
    struct node*prev;
    struct node * next;   //self referencing structure

};

struct node* head;

void Linkedlisttraversal(struct node *ptr){
    while(ptr->next!=head){
      cout<<ptr->data<<" ";
      ptr=ptr->next;
    }
    cout<<ptr->data;
}

void circular_Linkedlistcreation(){
     struct node *newnode,*temp;
     head=NULL;
     temp=head;
     int choice=1;

    while(choice){
       newnode=new struct node;           //Making a new node
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
       temp->next=head;

       cout<<"Enter your choice\n";
       cin>>choice;

     }

     cout<<endl;
     cout<<temp->next->data;

}



int main(){

    circular_Linkedlistcreation();
    cout<<"\nLinked list is \n";
    Linkedlisttraversal(head);
    



    
  return 0;

}



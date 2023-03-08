#include<iostream>
using namespace std;

struct node{
    int data;
    struct node * next;   //self referencing structure

};

void Linkedlisttraversal(struct node *ptr){
    while(ptr!=NULL){
      cout<<ptr->data<<" ";
      ptr=ptr->next;
    }
}

struct node *InsertAtFirst(struct node* head,int data)
{
   struct node* ptr= new struct node;
   ptr->next=head;
   ptr->data=data;
   return ptr;       //returns new value of head=ptr
   
};

struct node* InsertAtIndex(struct node* head,int data,int index){
    struct node* ptr= new struct node;
    struct node* p=head;
    int i=0;
    while(i!=index-1){
       p=p->next;
       i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    
    return head;

}


struct node *InsertAtLast(struct node* head,int data)
{
   struct node* ptr=head;
   struct node * p=new struct  node;
   
   while(ptr->next!=NULL){
       ptr=ptr->next;
   }
   
   p->data=data;
   ptr->next=p;
   p->next=NULL;

   return head;       
   
};

struct node* insertAfterNode(struct node *head, struct node *prevNode, int data){
    struct node * ptr = new struct node;
    ptr->data = data;
 
    ptr->next = prevNode->next;
    prevNode->next = ptr;
 
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
    
    cout<<"Linked list before insertion\n";
    Linkedlisttraversal(head);

    // cout<<"\n Linked list after insertion\n";
    // head=InsertAtFirst(head,4);
    // Linkedlisttraversal(head);


    // cout<<"Linked list after insertion\n";
    // head=InsertAtIndex(head,34,2);
    // Linkedlisttraversal(head);

    // cout<<"\n Linked list after insertion\n";
    // head=InsertAtLast(head,34);
    // Linkedlisttraversal(head);

    cout<<"\nLinked list after insertion\n";
    head=insertAfterNode(head,third,45);
    Linkedlisttraversal(head);
    

    


}
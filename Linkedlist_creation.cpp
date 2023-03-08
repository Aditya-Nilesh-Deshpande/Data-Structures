// #include<iostream>
// using namespace std;

// struct node{
//     int data;
//     struct node * next;   //self referencing structure

// };

// struct node* head;

// void Linkedlisttraversal(struct node *ptr){
//     while(ptr!=NULL){
//       cout<<ptr->data<<" ";
//       ptr=ptr->next;
//     }
// }

// void Linkedlistcreation(){
//      struct node *newnode,*temp;

//      temp=head;
//      int choice=1;

//     while(choice){
//        newnode=new struct node;           //Making a new node
//        cout<<"Enter the data\n";
//        cin>>newnode->data;
//        newnode->next=NULL;
       
//        if(head==NULL){
//            head=newnode;
//            temp=newnode;
//        }

//        else{
//            temp->next=newnode;
//            temp=newnode;
//        }

//        cout<<"Enter your choice\n";
//        cin>>choice;

//      }

// }





// int main(){

//     Linkedlistcreation();
//     cout<<"Linked list is \n";
//     Linkedlisttraversal(head);
    

    
//   return 0;

// }




#include<iostream>
using namespace std;


class node{
    int data;
    node* next;
public:
    // node(){
    //          
    // }

    void traversal();
    void create();
    void searching(int);

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


void node::searching(int key){
  node* temp=head;
  int found =1;
  while(temp!=NULL){
    if(temp->data==key){
    cout<<key<<"found in ";
    traversal();
    found=0;
    cout<<endl;
    return;
    }
    else{
      continue;
    }

  }
  
  if(found){
    cout<<"Not found\n";
  }
  

}

int main(){
    node temp;
    temp.create();
    temp.traversal();

  // int key;
  // cout<<"\nEnter the key\n";
  // cin>>key;
  // temp.searching(key);


    
    return 0;
}
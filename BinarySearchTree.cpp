#include <iostream>
using namespace std;

/*In a Binary Search Tree element which is greater is put to the right and which is smaller is put to the left */

class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int x)
    {
        data = x;
    }
    friend class BinarySearchTree;
};

class BinarySearchTree
{
    Node *root;
public:

    BinarySearchTree()
    {
        root = NULL;
    }
    Node* getroot(){
        return root;
    }
    void create(int);
    void insert(Node*,Node*);
    void traverse_inorder(Node*);
    void searchInBST(Node*,int);
    void deleteNodeWithValue(Node*,int);

};

void BinarySearchTree::create(int x)
{
    Node *newnode = new Node(x);
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL){
        cout<<"Created root node!!!"<<endl;
        root = newnode;
    }
    else{
      insert(root,newnode);
    } 

}


void BinarySearchTree::insert(Node* root,Node* newnode){

        cout<<"\nInserting left or right..."<<endl;
        cout<<"Greater values will be inserted to the right of node and smaller values to the left!!!"<<endl;
        
            if(newnode->data<root->data){
                if (root->left == NULL){    
                        root->left = newnode;
                        cout<<root->left->data<<" inserted to the left of "<<root->data<<" !!!"<<endl;
                        return;
                }
                else{
                        insert(root->left,newnode);
                }
            }

           else if(newnode->data>root->data){
                if (root->right == NULL){
                        root->right = newnode;
                        cout<<root->right->data<<" inserted to the right of "<<root->data<<" !!!"<<endl;
                        return;
                }
                else{
                        insert(root->right,newnode);
                }
           }

 
}

void BinarySearchTree::traverse_inorder(Node *root){
    if(root==NULL){
        return;
    }
    else{
        traverse_inorder(root->left);
        cout<<root->data<<" ";
        traverse_inorder(root->right);
    }
}


void BinarySearchTree::searchInBST(Node *root,int key){
    if(root==NULL){
        cout<<"Empty Tree"<<endl;
        return ;
    }
    else{
        Node* temp;
        Node* parent;

        temp=root;
        int flag =0;

        //Searching
        while((flag==0) && (temp!=NULL)){
            if(temp->data==key){
                flag=1;
            }
            else {
                parent=temp;  //Storing current temp
                if(temp->data>key){
                    temp=temp->left;
                }
                else{
                    temp=temp->right;
                }
            }

        }
    }
}

void BinarySearchTree:: deleteNodeWithValue(Node* root,int value){
    
    if(root==NULL){
        cout<<"Empty Tree"<<endl;
        return;
    }
    else {
        Node* temp;
        Node* parent;

        temp=root;
        int flag =0;

        //Searching
        while((flag==0) && (temp!=NULL)){
            if(temp->data==value){
                flag=1;
            }
            else {
                parent=temp;  //Storing current temp
                if(temp->data>value){
                    temp=temp->left;
                }
                else{
                    temp=temp->right;
                }
            }

        }

        if(flag==0 || temp==NULL){
            cout<<"\nSorry,the value to be deleted is not present in the BST";
        }

        else if(temp!=NULL){

            //For Leaf Node
            if((temp->left==NULL) && (temp->right==NULL)){
                //temp is the left child of parent
                if(temp==parent->left){ 
                    parent->left=NULL;
                }
                else{
                    parent->right=NULL;
                }
                cout<<"\nLeaf Node deleted!!!";
                delete temp;
            }

            //Internal node with only right child
            else if((temp->left==NULL) && (temp->right!=NULL)){  

                //if temp is the right child of parent having only right child 
                if(temp==parent->right){
                    // Right child of temp becomes right child of parent   
                    parent->right=temp->right;
                    temp->right=NULL;
                    cout<<"\nRight Internal Node with only right child deleted!!!";
                    delete temp;
                }

                //if temp is left child of parent having only right child
                else{
                    // Right child of temp becomes left child of parent 
                    parent->left=temp->right;
                    temp->right=NULL;
                    cout<<"\nLeft Internal Node with only right child deleted!!!";
                    delete temp;
                    
                }
                
            }

            //Internal node with only left child
            else if((temp->left!=NULL) && (temp->right==NULL)){  

                //temp is the right child of parent(right internal node) having only left child
                if(temp==parent->right){ 

                    // Left child of temp becomes right child of parent 
                    parent->right=temp->left;
                    temp->left=NULL;
                    cout<<"\nRight Internal Node with only left child deleted!!!";
                    delete temp;
                }

                //temp is the left child of parent(left internal node) having only left child
                else{

                    // Left child of temp becomes left child of parent 
                    parent->left=temp->left;
                    temp->left=NULL;
                    cout<<"\nLeft Internal Node with only left child deleted!!!";
                    delete temp;
                }
                

            }

            //Internal Node with 2 childs or root node with 2 childs
            else{
                cout<<"\n Sorry, the node with value "<<value<<" cannot be deleted as it has 2 childs!!!"<<endl;
            }
            
        }
    }
}


/* Create a binary tree
            10
          /    \
         8      15
        / \    /  \
       4   9  12   20


*/

int main()
{   BinarySearchTree obj;

    int n;
    cout<<"\nEnter the number of nodes you want to create ";
    cin>>n;

    for(int i=0;i<n;i++){
        int x;
        cout<<"\nEnter the data you want to enter in the node ";
        cin>>x;
        obj.create(x);
    }


    Node* r;
    r=obj.getroot();

    cout<<"\nInorder Traversal of BinarySearch Tree"<<endl;
    obj.traverse_inorder(r);

    int value;
    cout<<"\nEnter the node value to search ";
    cin>>value;

    obj.insert(r,value);

    // obj.searchInBST(r,value);
    
    // obj.deleteNodeWithValue(r,value);
    

    return 0;
}
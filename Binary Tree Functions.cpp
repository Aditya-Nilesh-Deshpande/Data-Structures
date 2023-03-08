#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

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
    friend class BinaryTree;
};

class BinaryTree
{
 Node *root;
    
public:

    BinaryTree()
    {
        root = NULL;
    }
    Node* getroot(){
        return root;
    }
    void create(int);
    void insert(Node*,Node*);
    Node* createBtree(int);
    void traverse_inorder(Node*);
    // void traverse_preorder(Node*);
    // void traverse_postorder(Node*);
    void search(Node*,int);
    void deleteEntiretree(Node*);

};

void BinaryTree::create(int x)
{
    Node *newnode = new Node(x);
    newnode->left = NULL;
    newnode->right = NULL;

    // Node *temp = root;
    

    if (root == NULL)
    {
        root = newnode;
        // temp = newnode;
        cout<<"Created the root node"<<endl;
    }
    else
    {  
        insert(root,newnode);
    } 

}


void BinaryTree::insert(Node* root,Node* newnode){

        cout<<"\nInserting left or right"<<endl;
        char choice;
        cout << "Enter where you want insert(L/R) of "<<root->data<<" ";
        cin >> choice;

        if (choice == 'L' || choice=='l'){

            if (root->left == NULL){    
                    root->left = newnode;
                    cout<<root->left->data<<" inserted to the left of "<<root->data<<" !!!"<<endl;
                    return;
            }
            else{
                    insert(root->left,newnode);
            }
        }

        else if(choice=='R' || choice=='r'){
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

void BinaryTree::traverse_inorder(Node *root){
    if(root==NULL){
        return;
    }
    else{
        traverse_inorder(root->left);
        cout<<root->data<<" ";
        traverse_inorder(root->right);
    }
}

// void BinaryTree::traverse_preorder(Node *root){
//     if(root==NULL){
//         return;
//     }
//     else{
//         cout<<root->data<<" ";
//         traverse_preorder(root->left);
//         traverse_preorder(root->right);
//     }
// }
// void BinaryTree::traverse_postorder(Node *root){
//     if(root==NULL){
//         return;
//     }
//     else{
//         traverse_postorder(root->left);
//         traverse_postorder(root->right);
//         cout<<root->data<<" ";
//     }
// }


void BinaryTree::search(Node* root,int key){
    if(root==NULL){
        return ;
    }
    else if(root->data==key){  
        cout<<key<<" is present in the tree"<<endl; 
        return ;
    }
    else{
        search(root->left,key);
        search(root->right,key);
    }
}

void BinaryTree::deleteEntiretree(Node* root){
    if(root==NULL){
        return;
    }
    else{
        deleteEntiretree(root->left);
        deleteEntiretree(root->right);
        cout<<"\n"<<root->data<<" deleted...";
        delete root;

    }
}


/* Create a binary tree
            1
          /   \
        2      3
       / \    / \
      4   5   6  7


*/

int main()
{   BinaryTree obj;

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
    r=obj.getroot();   //returns root

    cout<<"\nInorder Traversal"<<endl;
    obj.traverse_inorder(r);

    // cout<<"\nPreorder Traversal"<<endl;
    // obj.traverse_preorder(r);

    // cout<<"\nPostorder Traversal"<<endl;
    // obj.traverse_postorder(r);

    // cout<<"\nEnter the value you want to search in the Binary Tree "<<endl;
    // int key;
    // cin>>key;

    // obj.search(r,key);

    obj.deleteEntiretree(r);
    
    

    return 0;
}



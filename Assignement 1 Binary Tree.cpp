#include <iostream>
using namespace std;

class Node
{
    // Data Members
    int data;
    Node *right;
    Node *left;

public:
    Node()
    {
        data = 0;
        right = NULL;
        left = NULL;
    }
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }

    friend class BT;
    friend class stack;
};

class stack
{
    Node *s[50];
    int top = -1;

public:
    void push(Node *t1)
    {
        top++;
        s[top] = t1;
    }
    Node *pop()
    {
        Node *t1 = new Node;
        t1 = s[top];
        top--;
        return t1;
    }
    int empty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
            return 0;
    }
};

class BT
{
    Node *root;

public:
    BT()
    {
        root = NULL;
    }
    void setroot(Node *r)
    {
        root = r;
    }
    Node *getroot()
    {
        return root;
    }
    Node *create();
    void traverse_inorder(Node *);
    void nonrec_inorder(Node *);

    void traverse_preorder(Node *);
    void PreOrder_NonRecursive(Node *);

    void traverse_postorder(Node *);
    void PostOrder_Nonrecursive(Node *);
    void display_traversals();

    int heightOfTree(Node *);
    void count_leaves(Node *, int &);
    int count_internal(Node *);

    void Delete_Node(Node *);
    void Switch(Node *);

    Node *copy_tree(Node *);
    void Display_copy();
};

Node *BT::create()
{

    int x;
    cout << "Enter the Data(-1 to enter no data): ";
    cin >> x;
    Node *newnode = new Node(x); // Allocating Memory For New Node

    if (x == -1)
    {
        return NULL;
    }
    else
    {
        cout << "\nEnter the Left Child of " << newnode->data << endl;
        newnode->left = create(); // Again Function Is Get Called!(Recursion)
        cout << "\nEnter the Right Child of " << newnode->data << endl;
        newnode->right = create(); // Again Function Is Get Called!(Recursion)
        return newnode;
    }
    return NULL;
}

void BT::traverse_inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        traverse_inorder(root->left);
        cout << root->data << " ";
        traverse_inorder(root->right);
    }
}

void BT::traverse_preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->data << " ";
        traverse_preorder(root->left);
        traverse_preorder(root->right);
    }
}

void BT::traverse_postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        traverse_postorder(root->left);
        traverse_postorder(root->right);
        cout << root->data << " ";
    }
}
void BT::nonrec_inorder(Node *)
{
    // LEFT   ROOT  RIGHT
    stack s1;
    Node *t1 = root;

    while (!s1.empty() || t1 != NULL)
    {
        if (t1 != NULL)
        {
            s1.push(t1);
            t1 = t1->left;
        }
        else
        {
            t1 = s1.pop();
            cout << t1->data << " ";
            t1 = t1->right;
        }
    }
}

void BT::PreOrder_NonRecursive(Node *root)
{
    // ROOT  LEFT  RIGHT
    stack s1;
    Node *t1 = root;
    Node *prev = NULL;
    while (!s1.empty() || t1 != NULL)
    {
        if (t1 != NULL)
        {
            cout << t1->data << " ";
            s1.push(t1);
            t1 = t1->left;
        }
        else
        {
            prev = s1.pop();
            t1 = prev->right;
        }
    }
}
void BT::PostOrder_Nonrecursive(Node *root)
{
    // LEFT  RIGHT  ROOT
    stack s1, s2;
    Node *t1 = root;
    s1.push(t1);
    while (!s1.empty())
    {
        t1 = s1.pop();
        s2.push(t1);
        if (t1->left != NULL)
        {
            s1.push(t1->left);
        }
        if (t1->right != NULL)
        {
            s1.push(t1->right);
        }
    }
    while (!s2.empty())
    {
        root = s2.pop();
        cout << root->data << " ";
    }
}

void BT::display_traversals()
{
    // BT obj;

    cout << "\nInorder Traversal: ";
    traverse_inorder(root);
    cout << "\nNon Recursive Inorder Traversal: ";
    nonrec_inorder(root);

    cout << "\nPreorder Traversal: ";
    traverse_preorder(root);
    cout << "\nNon Recursive Preorder Traversal: ";
    PreOrder_NonRecursive(root);

    cout << "\nPostorder Traversal: ";
    traverse_postorder(root);
    cout << "\nNon Recursive Postorder Traversal: ";
    PostOrder_Nonrecursive(root);
    cout << endl;
}

int BT::heightOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_height = heightOfTree(root->left);
    int right_height = heightOfTree(root->right);
    if (left_height > right_height)
    {
        return (left_height + 1);
    }
    else
    {
        return (right_height + 1);
    }
}

void BT::count_leaves(Node *root, int &count)
{

    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
        {
            count++;
            return;
        }
        else
        {
            if (root->left != NULL)
            {
                count_leaves(root->left, count);
            }
            if (root->right != NULL)
            {
                count_leaves(root->right, count);
            }
        }
    }
}

// 1.Total Number of External Node = Internal Nodes + 1
int BT::count_internal(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return 0;
    }
    else
    {
        return 1 + count_internal(root->left) + count_internal(root->right);
    }
}

void BT::Delete_Node(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    else
    {
        Delete_Node(root->left);
        Delete_Node(root->right);
        cout << root->data << " deleted!\n";
        delete root;
    }
}

void BT::Switch(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        Node *temp; // temporary Variable,3 variable method
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        Switch(root->left); // Calling recursively!
        Switch(root->right);
    }
}

Node *BT::copy_tree(Node *t)
{
    Node *p;
    p = NULL;
    if (t != NULL)
    {
        p = new Node();
        p->data = t->data;
        p->left = copy_tree(t->left);
        p->right = copy_tree(t->right);
    }
    return p;
}
void BT::Display_copy()
{
    Node *t = copy_tree(root); // t points to the root of the copied tree
    cout << "\nTree Copied Successfully!" << endl;
    cout << "\nInorder Traversal of new Tree ";
    traverse_inorder(root);
}

/* Create a binary tree
            1
          /   \
        2      3
       / \    / \
      4   5   6  7


*/

int main()
{

    BT obj;
    Node *r = NULL;
    int count = 0;
    int choice;
    do
    {
        cout << "\n---------------------------------------------------------";
        cout << "\n0.Exit" << endl;
        cout << "1.Create BT - " << endl;
        cout << "2.Display Traversing (InOrder,PreOrder,PostOrder) - " << endl;
        cout << "3.Height For the Binary Tree - " << endl;
        cout << "4.Count number of leaves, number of internal nodes - " << endl;
        cout << "5.Delete All Nodes In Binary Tree - " << endl;
        cout << "6.Change a BT so that the roles of the left and right pointers are swapped at every node - " << endl;
        cout << "7.Copy this Binary Tree to Another - " << endl;
        cout << "---------------------------------------------------------\n";
        cout << "\nEnter the Choice - ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            r = obj.create();
            obj.setroot(r); // setting root = r
            break;
        case 2:
            obj.display_traversals();
            break;
        case 3:
            cout << "\nHeight of the tree is " << obj.heightOfTree(obj.getroot());
            break;
        case 4:
            cout << "\nNumber of leaf nodes in the tree are ";

            obj.count_leaves(obj.getroot(), count);
            cout << count;

            cout << "\nInternal nodes in the Btree are ";
            cout << obj.count_internal(obj.getroot());
            break;
        case 5:
            obj.Delete_Node(obj.getroot());
            obj.setroot(NULL); // set root=NULL
            cout << "Finished!!!";
            break;
        case 6:
            cout << "\nInorder Traversal is ";
            obj.traverse_inorder(obj.getroot());

            cout << "\nTree after Swapping ";
            obj.Switch(obj.getroot());
            cout << "\nNew Inorder Traversal is ";
            obj.traverse_inorder(obj.getroot());
            break;
        case 7:
            obj.Display_copy();
            break;

        default:
            break;
        }

    } while (choice != 0);
    return 0;
}
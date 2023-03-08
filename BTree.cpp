#include <iostream>
using namespace std;
#define SIZE 1000

template <class T>
class Stack
{
    friend class Node;
    friend class Tree;

public:
    Stack();
    void push(T k);
    T pop();
    T topElement();
    bool isFull();
    bool isEmpty();

private:
    int top;
    T st[SIZE];
};

template <class T>
Stack<T>::Stack() { top = -1; }

template <class T>
void Stack<T>::push(T k)
{
    if (isFull())
    {
        cout << "Stack is full\n";
    }
    top = top + 1;
    st[top] = k;
}

template <class T>
bool Stack<T>::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

template <class T>
bool Stack<T>::isFull()
{
    if (top == (SIZE - 1))
        return 1;
    else
        return 0;
}

template <class T>
T Stack<T>::pop()
{
    T popped_element = st[top];
    top--;
    return popped_element;
}

template <class T>
T Stack<T>::topElement()
{
    T top_element = st[top];
    return top_element;
}

//----------------------------------------------------------------------------------------------------------------------------//

class Node
{
    int data;
    Node *lchild;
    Node *rchild;

public:
    friend class Tree;
    Node()
    {
        lchild = NULL;
        rchild = NULL;
    }
};

//----------------------------------------------------------------------------------------------------------------------------//

class Tree
{

public:
    Node *root;
    Node *maketree();
    Tree()
    {
        root = NULL;
    }
    void create()
    {
        root = maketree();
    }
    void preorder_recur(Node *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            preorder_recur(root->lchild);
            preorder_recur(root->rchild);
        }
    }
    void inorder_recur(Node *root)
    {
        if (root != NULL)
        {
            inorder_recur(root->lchild);
            cout << root->data << " ";
            inorder_recur(root->rchild);
        }
    }
    void postorder_recur(Node *root)
    {
        if (root != NULL)
        {
            postorder_recur(root->lchild);
            postorder_recur(root->rchild);
            cout << root->data << " ";
        }
    }
    void preorder_nrecur(Node *root)
    {

        if (root == NULL)
            return;

        Stack<Node *> s1;
        Node *curr = root;
        while (!s1.isEmpty() || curr != NULL)
        {
            while (curr != NULL)
            {
                cout << curr->data << " ";
                if (curr->rchild)
                    s1.push(curr->rchild);

                curr = curr->lchild;
            }

            if (s1.isEmpty() == false)
            {
                curr = s1.st[s1.top];
                s1.pop();
            }
        }
    }

    void inorder_nrecur(Node *root)
    {
        Stack<Node *> s;
        Node *curr = root;
        while (curr != NULL || s.isEmpty() == false)
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->lchild;
            }
            curr = s.st[s.top];
            s.pop();
            cout << curr->data << " ";
            curr = curr->rchild;
        }
    }

    void postorder_nrecur(Node *root)
    {

        if (root == NULL)
            return;
        Stack<Node *> s1, s2;
        s1.push(root);
        Node *node;
        while (!s1.isEmpty())
        {
            node = s1.st[s1.top];
            s1.pop();
            s2.push(node);
            if (node->lchild)
                s1.push(node->lchild);
            if (node->rchild)
                s1.push(node->rchild);
        }
        while (!s2.isEmpty())
        {
            node = s2.st[s2.top];
            s2.pop();
            cout << node->data << " ";
        }
    }
    int leafCount(Node *t)
    {
        if (t == NULL)
        {
            return 0;
        }
        if ((t->lchild == NULL) && (t->rchild == NULL))
        {
            return 1;
        }
        return leafCount(t->lchild) + leafCount(t->rchild);
    }
    void traversal()
    {
        int a;
        cout << "Traversal Techniques:\n 1.Preorder (Recursive)\n 2.Postorder (Recursive)\n 3.Inorder (Recursive)\n 4.Preorder (Non-Recursive)\n 5.Postorder (Non-Recursive)\n 6.Inorder (Non-Recursive)\n";
        cout << "Enter choice" << endl;
        cin >> a;
        if (a == 1)
        {
            preorder_recur(root);
        }
        if (a == 2)
        {
            postorder_recur(root);
        }
        if (a == 3)
        {
            inorder_recur(root);
        }
        if (a == 4)
        {
            preorder_nrecur(root);
        }
        if (a == 5)
        {
            postorder_nrecur(root);
        }
        if (a == 6)
        {
            inorder_nrecur(root);
        }
    }
    int height(Node *x)
    {
        int leftHeight, rightHeight;
        if (x == NULL)
        {
            // cout<<"0"<<endl;
            return 0;
        }
        else
        {
            leftHeight = height(x->lchild);
            rightHeight = height(x->rchild);
        }
        if (leftHeight > rightHeight)
        {
            return (leftHeight + 1);
        }
        else
        {
            return (rightHeight + 1);
        }
    }
    void deleteTree(Node *x)
    {
        if (x == NULL)
        {
            return;
        }
        deleteTree(x->lchild);
        deleteTree(x->rchild);

        delete x;
    }
    void swapBranches(Node *q)
    {
        if (q != NULL)
        {
            Node *temp;
            temp = q->lchild;
            q->lchild = q->rchild;
            q->rchild = temp;

            swapBranches(q->lchild);
            swapBranches(q->rchild);
        }
    }
    void Swap()
    {
        swapBranches(root);
    }
};

Node *Tree::maketree()
{
    Node *temp;
    char ch;
    temp = new Node;
    cout << "Enter data:" << endl;
    cin >> temp->data;
    cout << "Enter Right Child? (y/n)" << endl;
    cin >> ch;
    if (ch == 'y')
    {
        temp->rchild = maketree();
    }
    cout << "Enter Left Child? (y/n)" << endl;
    cin >> ch;
    if (ch == 'y')
    {
        temp->lchild = maketree();
    }
    else
    {
        return temp;
    }
    return temp;
}
int main()
{
    Tree t1;
    int x = 1;
    while (x != 0)
    {
        cout << "1. Create a tree \n 2. Traversals\n 3. Height of tree \n 4. Leaf count \n 5. Delete tree \n 6. Swap LST and RST \n PRESS 0 TO END" << endl;
        cin >> x;
        if (x == 0)
        {
            return 0;
        }
        else if (x == 1)
        {
            t1.create();
        }
        else if (x == 2)
        {
            t1.traversal();
            cout << endl;
        }
        else if (x == 3)
        {
            int h = t1.height(t1.root);
            cout << h << endl;
        }
        else if (x == 4)
        {
            cout << t1.leafCount(t1.root) << endl;
        }
        else if (x == 5)
        {
            t1.deleteTree(t1.root);
            cout << "Tree deleted successfully" << endl;
        }
        else if (x == 6)
        {
            t1.Swap();
        }
    }
    return 0;
}
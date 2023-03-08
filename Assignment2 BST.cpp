#include <iostream>
using namespace std;

class Node
{
    string keyword;
    string meaning;
    Node *left;
    Node *right;

public:
    Node()
    {
        keyword = "";
        meaning = "";
        left = NULL;
        right = NULL;
    }
    Node(string x, string y)
    {
        keyword = x;
        meaning = y;
        left = NULL;
        right = NULL;
    }
    friend class BST;
};

class BST
{
    Node *root;

public:
    BST()
    {
        root = NULL;
    }
    Node *getroot()
    {
        return root;
    }

    void create();

    void inorderTraversal(Node *);
    void preorderTraversal(Node *);
    void postorderTraversal(Node *);
    void displayTraversals();

    int search(int &, string, Node *&, Node *&);
    void insert(Node *&, Node *&);

    void Switch(Node *);
    void updateMeaning(Node *&, Node *&);

    void deleteKeyword(string, Node *&, Node *&);
    void delete1BST(string, Node *&, Node *&);
    void delete2BST(string, Node *&, Node *&);

    void updateKeyword(Node *&, Node *&);
};

void BST::create()
{
    char choice;

    do
    {
        string s1, s2;
        cout << "\nEnter the keyword: ";
        cin >> s1;

        cout << "\nEnter the meaning: ";
        cin.ignore();
        getline(cin, s2);

        Node *newnode = new Node(s1, s2);
        int flag = 0;

        if (root == NULL)
        {
            root = newnode;
        }
        else
        {
            Node *temp = root;
            do
            {
                if (newnode->keyword < temp->keyword)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = newnode;
                        flag = 1;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else if (newnode->keyword > temp->keyword)
                {
                    if (temp->right == NULL)
                    {
                        temp->right = newnode;
                        flag = 1;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
                else
                {
                    cout << "\nNode Already exists!!! " << endl;
                    return;
                }

            } while (flag == 0 && temp != NULL);
        }

        cout << "\nDo you want to continue(y/n)";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
}

void BST::inorderTraversal(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    else
    {
        inorderTraversal(root->left);
        cout << root->keyword << " : " << root->meaning << endl;
        inorderTraversal(root->right);
    }
}
void BST::preorderTraversal(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->keyword << " : " << root->meaning << endl;
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void BST::postorderTraversal(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    else
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->keyword << " : " << root->meaning << endl;
    }
}

void BST::displayTraversals()
{
    cout << "\nInorder Traversal is " << endl;
    inorderTraversal(root);

    cout << "\nPreorder Traversal is " << endl;
    preorderTraversal(root);

    cout << "\nPostorder Traversal is " << endl;
    postorderTraversal(root);
}

int BST::search(int &count, string key, Node *&loc, Node *&parent)
{
    // loc is set if node is found
    // parent is the parent of loc

    if (root == NULL)
    {
        loc = parent = NULL;
        return count;
    }
    loc = parent = NULL;

    Node *curr = root;
    while (curr != NULL)
    {
        if (key == curr->keyword)
        {
            loc = curr;
            return count;
        }
        else if (key < curr->keyword)
        {
            parent = curr;     // storing the current curr in parent
            curr = curr->left; // moving curr
            count++;
        }
        else
        {
            parent = curr;
            curr = curr->right;
            count++;
        }
    }
    return count;
}
void BST::insert(Node *&loc, Node *&parent)
{

    string s1, s2;
    cout << "\nEnter the keyword: ";
    cin >> s1;

    cout << "\nEnter the meaning: ";
    cin.ignore();
    getline(cin, s2);

    int count = 0;
    count = search(count, s1, loc, parent); // To check if the node is already present
    // inserting at the leaf node;

    if (loc != NULL)
    {
        cout << "\nNode already exists!";
        return;
    }

    Node *newnode = new Node(s1, s2);

    if (parent == NULL)
    {
        root = newnode;
        cout << "Number of counts required to search your node is " << count << endl;
    }
    else if (newnode->keyword < parent->keyword)
    {
        parent->left = newnode;

        cout << "\nNode Inserted to the left of " << parent->keyword << endl;
        cout << "Number of counts required to search your node is " << count << endl;
    }
    else
    {
        parent->right = newnode;

        cout << "\nNode Inserted to the right of " << parent->keyword << endl;
        cout << "Number of counts required to search your node is " << count << endl;
    }
}

void BST::Switch(Node *root)
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

void BST::updateMeaning(Node *&loc, Node *&parent)
{

    string s1, s2;
    cout << "\nEnter the keyword whose meaning you want to update- ";
    cin >> s1;

    cout << "\nEnter the new meaning- ";
    cin.ignore();
    getline(cin, s2);

    int count = 0;
    count = search(count, s1, loc, parent); // To check if the node is already present

    if (loc == NULL)
    {
        cout << "\nNo such node found!!! ";
        return;
    }

    else
    {
        loc->meaning = s2;
        cout << "\n"
             << loc->keyword << " Meaning is changed!!!";
        return;
    }
}

void BST::deleteKeyword(string s1, Node *&loc, Node *&parent)
{

    int count = 0;
    count = search(count, s1, loc, parent); // To check if the node is already present

    if (loc == NULL)
    {
        cout << "\nNo such node found!!! ";
        return;
    }
    else
    {

        if (loc->left != NULL && loc->right != NULL)
        { // Node with 2 childs
            delete2BST(s1, loc, parent);
        }
        else
        {
            delete1BST(s1, loc, parent);
        }
    }
}

void BST::delete1BST(string s1, Node *&loc, Node *&parent)
{

    Node *child;
    if (loc == root && loc->left != NULL)
    { // delete root node with left child only
        child = loc->left;
        root = child;
        cout << "\n"
             << loc->keyword << " deleted!!!";
        delete loc;
        return;
    }
    else if (loc == root && loc->right != NULL)
    { // delete root node with right child only
        child = loc->right;
        root = child;
        cout << "\n"
             << loc->keyword << " deleted!!!";
        delete loc;
        return;
    }

    if (loc->left == NULL && loc->right == NULL)
    { // delete leaf node
        child = NULL;
    }
    else if (loc->left != NULL)
    {
        child = loc->left;
    }
    else
    {
        child = loc->right;
    }

    if (loc == parent->left)
    { // if loc is the left child of parent
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }
    cout << "\n"
         << loc->keyword << " deleted!!!";
    delete loc;
}

void BST::delete2BST(string s1, Node *&loc, Node *&parent)
{

    Node *ptr1 = loc;
    Node *inordersucc = loc->right;

    while (inordersucc->left != NULL)
    {
        ptr1 = inordersucc; // parent of inordersucc
        inordersucc = inordersucc->left;
    }

    loc->keyword = inordersucc->keyword;
    loc->meaning = inordersucc->meaning;

    delete1BST(s1, inordersucc, ptr1);
}

void BST::updateKeyword(Node *&loc, Node *&parent)
{
    string s1;
    cout << "\nEnter the keyword you want to update: ";
    cin >> s1;

    string s2;
    int count = 0;
    count = search(count, s1, loc, parent); // To check if the node is already present

    if (loc == NULL)
    {
        cout << "\nNo such node found!!! ";
        return;
    }

    else
    {
        s2 = loc->meaning; // Storing the meaning of the word before deleting

        deleteKeyword(s1, loc, parent);

        // insert(loc,parent);
        // Same as insert function

        string s;
        cout << "\nEnter the new keyword: ";
        cin >> s;

        int count = 0;
        count = search(count, s, loc, parent); // To check if the node is already present
        // inserting at the leaf node;

        if (loc != NULL)
        {
            cout << "\nNode already exists!";
            return;
        }

        Node *newnode = new Node(s, s2);

        if (parent == NULL)
        {
            root = newnode;
            cout << "Number of counts required to search your node is " << count << endl;
        }
        else if (newnode->keyword < parent->keyword)
        {
            parent->left = newnode;

            cout << "\nNode Inserted to the left of " << parent->keyword << endl;
            cout << "Number of counts required to search your node is " << count << endl;
        }
        else
        {
            parent->right = newnode;

            cout << "\nNode Inserted to the right of " << parent->keyword << endl;
            cout << "Number of counts required to search your node is " << count << endl;
        }
    }
}
int main()
{
    BST obj;
    Node *loc;
    Node *parent;

    int choice;
    do
    {

        cout << "\n---------------------------------------------------------";
        cout << "\n0.Exit" << endl;
        cout << "1.Create a Dictionary using BST - " << endl;
        cout << "2.Display Traversal (InOrder,PreOrder,PostOrder) - " << endl;
        cout << "3.Inserting a node in the Dictionary - " << endl;
        cout << "4.Display in Ascending and Descending order - " << endl;
        cout << "5.Update the meaning of a given keyword - " << endl;
        cout << "6.Update a keyword without changing its meaning - " << endl;

        cout << "---------------------------------------------------------\n";

        cout << "\nEnter the Choice - ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.create();
            break;
        case 2:
            obj.displayTraversals();
            break;
        case 3:

            obj.insert(loc, parent);

            cout << "\nInorder Traversal is " << endl;
            obj.inorderTraversal(obj.getroot());
            break;

        case 4:
            cout << "\nDictionary in Ascending order is " << endl;
            obj.inorderTraversal(obj.getroot());

            cout << "\nDictionary in Descending order is " << endl;
            obj.Switch(obj.getroot());
            obj.inorderTraversal(obj.getroot());
            break;
        case 5:
            obj.updateMeaning(loc, parent);

            cout << "\nInorder Traversal is " << endl;
            obj.inorderTraversal(obj.getroot());
            break;

        case 6:
            obj.updateKeyword(loc, parent);

            cout << "\nInorder Traversal is " << endl;
            obj.inorderTraversal(obj.getroot());
            break;
        case 0:
            cout << "\nThank You!!!" << endl;
            break;

        default:
            cout << "\nBetter Luck Next Time!!!";
            break;
        }

    } while (choice != 0);

    return 0;
}
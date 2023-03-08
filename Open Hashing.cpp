#include <iostream>
#define MAX 26
using namespace std;

class HashEntry
{

    string key;
    string value;
    HashEntry *next;

public:
    HashEntry()
    {
        key = "NONE";
        value = "NONE";
        next = NULL;
    }
    HashEntry(string k, string v)
    {
        key = k;
        value = v;
        next = NULL;
    }
    friend class Dictionary;
};

class Dictionary
{

    HashEntry *ht[MAX];

public:
    Dictionary()
    {
        for (int i = 0; i < MAX; i++)
        {
            ht[i] = NULL;
        }
    }
    int hashFunction(string);
    void insert();
    void display();
    int search(string);
    void deleteKey(string);
};

int Dictionary::hashFunction(string key)
{

    char first = key[0];

    int j;
    if (first >= 'A' && first <= 'Z')
    {
        j = first - 'A';
    }
    else
    {
        j = first - 'a';
    }

    return j;
}

void Dictionary::insert()
{

    char choice;

    do
    {
        string key;
        cout << "\nEnter the key you want to add in the dictionary ";
        cin >> key;

        string value;
        cout << "\nEnter the value ";
        cin >> value;

        int index;
        index = hashFunction(key);

        HashEntry *temp = ht[index];                    // To traverse through the linked list
        HashEntry *newnode = new HashEntry(key, value); // newnode

        if (ht[index] == NULL)
        {
            ht[index] = newnode;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }

        cout << "\nDo you want to continue(Y/N) ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');
}

void Dictionary::display()
{

    HashEntry *ptr;
    for (int i = 0; i < MAX; i++)
    {
        ptr = ht[i];
        while (ptr != NULL)
        {
            cout << ptr->key << " : " << ptr->value << endl;
            ptr = ptr->next;
        }
    }
    cout << endl;
}
int Dictionary::search(string key)
{
    int hashIndex = hashFunction(key);

    HashEntry *temp = ht[hashIndex];

    while (temp != NULL)
    {
        if (temp->key == key)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void Dictionary::deleteKey(string key)
{

    int hashIndex = hashFunction(key);

    HashEntry *temp = ht[hashIndex];
    HashEntry *prev = NULL;

    while (temp != NULL)
    {
        if (temp->key == key)
        {
            if (temp == ht[hashIndex])
            {
                ht[hashIndex] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            temp->next = NULL;
            cout << "\n"
                 << temp->key << " deleted successfully!!!";
        }
        prev = temp;
        temp = temp->next;
    }
    cout << endl;
}
int main()
{

    Dictionary obj;
    string key;
    string word;
    int ch;

    do
    {
        cout << "\n---------------------------------------------------------";
        cout << "\n0.Exit" << endl;
        cout << "1.Add Word To the Dictionary - " << endl;
        cout << "2.Display Dictionary " << endl;
        cout << "3.Search a Word in the Dictionary " << endl;
        cout << "4.Delete a Word from the Dictionary " << endl;
        cout << "---------------------------------------------------------\n";

        cout << "\nEnter choice:";
        cin >> ch;

        switch (ch)
        {
        case 1:
            obj.insert();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            int f;

            cout << "\nEnter the key you want to search for: ";
            cin >> key;

            f = obj.search(key);
            if (f)
            {
                cout << "\nWord Found!!!";
            }
            else
            {
                cout << "\nSorry,Word Not Found!!!";
            }

            break;

        case 4:

            cout << "\nEnter the Word you want to delete ";
            cin >> word;

            obj.deleteKey(word);
            break;

        default:
            break;
        }

    } while (ch != 0);

    return 0;
}

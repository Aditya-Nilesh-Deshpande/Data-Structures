#include <iostream>
#define MAX 10
using namespace std;

class HashTable
{
    long phoneno;
    string name;

public:
    HashTable()
    {
        phoneno=0;
        name="";
    }
    HashTable(long x,string n){
        phoneno=x;
        name=n;
    }

    friend class PhoneBook;
};

class PhoneBook
{
    HashTable ht[MAX];

public:
    PhoneBook()
    {
        for (int i = 0; i < MAX; i++)
        {
            ht[i].phoneno = -1;
            ht[i].name="ANONYMOUS";
        }
    }

    int hashFunction(long);
    void insert();
    void display();
    int search(long);
    void linearProbingWithoutReplacement(long, long,string);
    void linearProbingWithReplacement(long, long,string);
    void deletePhoneno(long);
};

int PhoneBook::hashFunction(long x)
{
    long j;
    j = x % MAX;
    return j;
}

void PhoneBook::insert()
{
    char choice;
    do
    {
        long x;
        cout << "\nEnter the phone number you want to add in the phonebook: ";
        cin >> x;

        string n;
        cout<<"\nEnter the name of the person holding the phoneno: ";
        cin>>n;

        long start;
        start = hashFunction(x); // getting hashindex

        if (ht[start].phoneno == -1)
        {
            ht[start].phoneno = x;
            ht[start].name=n;
        }
        else
        { // Collision Occurs

            int choice;
            cout << "\nCollision Occured!!!" << endl;
            cout << "Enter Your Choice(1->withoutReplacement, 2->withReplacement)";
            cin >> choice;

            if (choice == 1)
            {
                linearProbingWithoutReplacement(x, start,n);
            }
            else if (choice == 2)
            {
                linearProbingWithReplacement(x, start,n);
            }
            else
            {
                cout << "\nEnter choice either 1 or 2";
            }
        }

        cout << "\nDo you want to continue(Y/N)";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');
}

void PhoneBook::linearProbingWithoutReplacement(long x, long start,string n)
{

    long i = (start + 1)%MAX;
    bool inserted = false;

    while (i != start)
    {
        if (ht[i].phoneno == -1)
        {
            ht[i].phoneno= x;
            ht[i].name=n;
            inserted = true;
            break;
        }
        i = (i + 1) % MAX;
    }
    if (!inserted)
    {
        cout << "\nSorry, cannot insert as PhoneBook is full";
    }
}

void PhoneBook::linearProbingWithReplacement(long x, long start,string n)
{

    long i = (start + 1)%MAX;
    bool inserted = false;

    if (hashFunction(x) == hashFunction(ht[start].phoneno))
    {
        while (i != start)
        {
            if (ht[i].phoneno == -1)
            {
                ht[i].phoneno = x;
                ht[i].name=n;
                inserted = true;
                break;
            }
            i = (i + 1) % MAX;
        }
        if (!inserted)
        {
            cout << "\nSorry, cannot insert as Hashtable is full";
        }
    }
    else
    { /*  The data at start is not a synonym of x.So it must be linearly probed and x must be placed at its proper position  */

        cout << "The element present is not a synonym of " << x << endl;
        cout << "Replacing " << x << " and finding new position for " << ht[start].phoneno;
        while (i != start)
        {
            if (ht[i].phoneno == -1)
            {
                ht[i].phoneno = ht[start].phoneno;
                ht[i].name=ht[start].name;
                inserted = true;
                break;
            }
            i = (i + 1) % MAX;
        }
        ht[start].phoneno = x; // Placing x at its proper position
        ht[start].name=n;

        if (!inserted)
        {
            cout << "\nSorry, cannot insert as Hashtable is full";
        }
    }
}

int PhoneBook::search(long key)
{

    long hashIndex = hashFunction(key);
    if (ht[hashIndex].phoneno == key)
    {
        return hashIndex;
    }
    else
    {
        long j = (hashIndex + 1)%MAX;
        while (j != hashIndex)
        {
            if (ht[j].phoneno == key)
            {
                return j;
            }
            j = (j + 1) % MAX;
        }
        return -1;
    }
}
void PhoneBook::display()
{
    for (int i = 0; i < MAX; i++)
    {
        cout << ht[i].name << " : "<<ht[i].phoneno<<endl;
    }
}

void PhoneBook:: deletePhoneno(long key){

    long loc;
    loc=search(key);

    if(loc==-1){
        cout<<"\nSorry,No such Phone Number Found!!!";
    }
    else{
        ht[loc].phoneno=-1;
        ht[loc].name="ANONYMOUS";
        cout<<"\nPhone Number deleted succesfully!!!";
    }
}
int main()
{   PhoneBook obj;
    int ch;

    do{
    cout<<"\n---------------------------------------------------------";
    cout<<"\n0.Exit"<<endl;
    cout << "1.Add PhoneNumber To the PhoneBook - " << endl;
    cout << "2.Display PhoneBook " << endl;
    cout << "3.Search a Phone Number " << endl;
    cout << "4.Delete a Phone Number from the PhoneBook " << endl;
    cout<<"---------------------------------------------------------\n";

    cout << "\nEnter choice:";
    cin >> ch;


    switch(ch){
        case 1:
            obj.insert();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            long key;
            cout << "\nEnter the value you want to search ";
            cin >> key;

            long found;
            found = obj.search(key);

            if (found == -1)
            {
                cout << "\nSorry, Element not found!!!!";
            }
            else
            {
                cout << "\nElement found at index " << found;
            }
            break;

        case 4:
            long ph;
            cout<<"\nEnter the Phone Number you want to delete ";
            cin>>ph;

            obj.deletePhoneno(ph);
            break;

        default:
            break;
        }

    }while(ch!=0);

    return 0;
}
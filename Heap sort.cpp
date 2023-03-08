/*Write  a  C++/Java  program  to  implement  topological  sorting  on  graph  using  object
oriented programming features Design necessary class. .( Use of graph)
*/

#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;
class DataBase
{
    int *Heap;
    int size;

public:
    DataBase()
    {
        size = 0;
        Heap = new int[size];
    }
    void Insert(int key)
    {
        size++;
        Heap[size - 1] = key;
        int ptr = size - 1;
        while (ptr > 0)
        {
            int parent = (ptr - 1) / 2;
            if (Heap[ptr] < Heap[parent])
            {
                int temp = Heap[ptr];
                Heap[ptr] = Heap[parent];
                Heap[parent] = temp;
                ptr = parent;
            }
            else
            {
                break;
            }
        }
    }
    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << Heap[i] << "  ";
        }
        cout << endl;
    }
    void Delete()
    {
        if (size == 0)
        {
            cout << "\nHeap is Empty!" << endl;
        }
        else
        {
            int ptr = 0, lchild = 1, rchild = 2;
            cout<<Heap[0]<<"  ";
            int last = Heap[size - 1];
            size=size-1;
            while (rchild <= size - 1)
            {
                if (last <= Heap[lchild] && last <= Heap[rchild])
                {
                    // q[i] = Heap[ptr];
                    Heap[ptr] = last;
                    break;
                }
                if (Heap[lchild] < Heap[rchild])
                {
                    Heap[ptr] = Heap[lchild];
                    ptr = lchild;
                }
                else
                {
                    Heap[ptr] = Heap[rchild];
                    ptr = rchild;
                }
                lchild = 2 * ptr + 1;
                rchild = 2 * ptr + 2;
            }
            if(lchild==size-1 && last>Heap[lchild]){
                Heap[ptr]=Heap[lchild];
                ptr=lchild;
            }
            Heap[ptr]=last;
        }
    }
    void Sorting()
    {
        for(int i=size-1;i>=0;i--){
            Delete();
        }
    }
};
int main()
{
    DataBase d;
    int ch;
    do
    {
        cout << "\n1.Insert Data(In Tree) - " << endl;
        cout << "2.Display Heap Sort - " << endl;
        cout<<"3.Display Sorting - "<<endl;
        cout << "\nEnter the Choice - ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int x;
            cout << "\nEnter the Element - ";
            cin >> x;
            d.Insert(x);
            break;
        case 2:
            d.Display();
            break;
        case 3:
            d.Sorting();
            break;
        default:
            break;
        }
    } while (ch != 0);

    return 0;
}
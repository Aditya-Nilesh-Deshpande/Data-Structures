#include <iostream>
using namespace std;
class Heapsort
{
    int n;
    int *arr;

public:
    Heapsort()
    {
        cout << "Enter the total number of elements" << endl;
        cin >> n;
        arr = new int[n];
    }
    void createarray()
    {
        cout << "Enter the elements in the heap" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
    void Heapify(int arr[], int n, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && arr[l] > arr[largest])
        {
            largest = l;
        }
        if (r < n && arr[r] > arr[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            Heapify(arr, n, largest);
        }
    }
    void CreateHeap()
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            Heapify(arr, n, i);
        }
        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[i], arr[0]);
            Heapify(arr, i, 0);
        }
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    Heapsort h;
    h.createarray();
    h.CreateHeap();
    h.print();
}
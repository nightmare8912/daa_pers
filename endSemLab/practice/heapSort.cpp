#include <iostream>
#include <time.h>
using namespace std;

int tempSize;
long int count = 0;

void maxHeapify(int arr[], int i)
{
    int left, right, largest;
    left = 2 * i;
    right = 2 * i + 1;
    largest = i;

    if (left <= tempSize && arr[left] > arr[largest])
        largest = left;

    if (right <= tempSize && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        count++;
        maxHeapify(arr, largest);
    }
}

void buildHeap(int arr[])
{
    for (int i = tempSize / 2; i >= 1; i--)
        maxHeapify(arr, i);
}

void heapSort(int arr[])
{
    buildHeap(arr);
    for (int i = tempSize; i >= 2; i--)
    {
        swap(arr[1], arr[i]);
        tempSize--;
        maxHeapify(arr, 1);
    }
}

int main()
{
    time_t st, end;
    double etime;
    int size;

    cout << "Enter the number of elements: ";
    cin >> size;

    tempSize = size;

    int arr[tempSize + 1];
    srand((long int)clock());
    for (int i = 1; i <= size; i++)
        arr[i] = rand() % 30;

    cout << "Before sorting: " << endl;
    for (int i = 1; i <= size; i++)
        cout << arr[i] << " ";
    st = clock();
    heapSort(arr);
    end = clock();
    etime = (double)(end - st)/CLOCKS_PER_SEC;
    cout << "\n";
    cout << "After sorting: " << endl;

    for (int i = 1; i <= size; i++)
        cout << arr[i] << " ";
    
    cout << "\n";
    cout << "Time taken: " << etime << " seconds" << endl;
    cout << "Active operations: " << count; 
}
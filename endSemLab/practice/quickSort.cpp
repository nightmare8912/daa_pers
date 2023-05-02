#include <iostream>
#include <time.h>
using namespace std;

long int count = 0;

int partition(int arr[], int p, int r)
{
    int pivot = arr[r];
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            count++;
            swap(arr[j], arr[i]);
        }
    }

    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int main()
{
    int size;
    cout << "Enter number of elements: ";
    cin >> size;
    time_t st, end;
    double etime;
    int arr[size];

    for (int i = 1; i <= size; i++) 
        arr[i] = rand() % 30;
    
    cout << "Before sorting: " << "\n";
    for (int i = 1; i <= size; i++)
        cout << arr[i] << " ";
    st = clock();
    quickSort(arr, 1, size);
    end = clock();
    cout << "\n";
    etime = (double)(end - st)/CLOCKS_PER_SEC;
    cout << "After sorting: " << "\n";
    for (int i = 1; i <= size; i++)
        cout << arr[i] << " ";
    
    cout << "\n";
    cout << "Time taken: " << etime << " seconds" << "\n";
    cout << "Active operations: " << count;
}
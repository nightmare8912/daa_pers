#include <iostream>
#include <time.h>
using namespace std;

int size = 0;
long int count = 0;

void merge(int arr[], int p, int q, int r)
{
    int i, j, k;
    i = k = p;
    j = q + 1;

    int tempArray[size];

    while (i <= q && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            tempArray[k] = arr[i];
            i++;
        }
        else
        {
            tempArray[k] = arr[j];
            j++;
        }
        count++;
        k++;
    }

    if (i > q)
    {
        while (j <= r)
        {
            tempArray[k] = arr[j];
            j++; k++;
            count++;
        }
    }
    else 
    {
        while (i <= q)
        {
            tempArray[k] = arr[i];
            i++; k++;
            count++;
        }
    }
    for (k = p; k <= r; k++)
        arr[k] = tempArray[k];
}

void mergeSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main()
{

    time_t st, end;
    double etime;

    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size + 1];
    srand((long int)clock());
    for (int i = 1; i <= size; i++)
        arr[i] = rand() % 30;

    cout << "Before sorting: " << endl;
    for (int i = 1; i <= size; i++)
        cout << arr[i] << " ";
    st = clock();
    mergeSort(arr, 1, size);
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
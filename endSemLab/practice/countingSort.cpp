#include <iostream>
#include <time.h>
using namespace std;

long int count = 0;
int size;

int getMax(int arr[])
{
    int max = arr[1];
    for (int i = 1; i <= size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countSort(int arr[], int sortedArray[])
{
    int k = getMax(arr);
    int countArray[k + 1];

    for (int i = 0; i <= k; i++)
        countArray[i] = 0;
    
    for (int i = 1; i <= size; i++)
        countArray[arr[i]] += 1;

    for (int i = 1; i <= k; i++)
        countArray[i] += countArray[i - 1];

    for (int j = size; j >= 1; j--)
    {
        count++;
        sortedArray[countArray[arr[j]]] = arr[j];
        countArray[arr[j]] -= 1;
    }
}

int main()
{
    time_t st, end;
    double etime;

    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size + 1], sortedArray[size + 1];
    srand((long int)clock());
    for (int i = 1; i <= size; i++)
        arr[i] = rand() % 30;

    cout << "Before sorting: " << endl;
    for (int i = 1; i <= size; i++)
        cout << arr[i] << " ";
    st = clock();
    countSort(arr, sortedArray);
    end = clock();
    etime = (double)(end - st)/CLOCKS_PER_SEC;
    cout << "\n";
    cout << "After sorting: " << endl;

    for (int i = 1; i <= size; i++)
        cout << sortedArray[i] << " ";
    
    cout << "\n";
    cout << "Time taken: " << etime << " seconds" << endl;
    cout << "Active operations: " << count;
}
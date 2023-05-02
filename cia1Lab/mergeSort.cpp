#include <iostream>
#include<time.h>
using namespace std;
void merge(int arr[], int p, int q, int r)
{
    int i = p, j = q + 1, k = p;
    int temp[r];
    while (i <= q && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    if (i > q)
    {
        while (j <= r)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    else if (j > q)
    {
        while (i <= q)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }

    for (int i = p; i <= r; i++)
    {
        arr[i] = temp[i];
    }
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
    clock_t st,end;
    double etime;
    srand((long int)clock());
    for (;;)
    {
        int n;
        cout << "Enter n: ";
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 20;
            cout << arr[i] << " ";
        }
        cout << endl;
        st = clock();
        mergeSort(arr, 0, n);
        end = clock();
        etime=((double)(end-st)/CLOCKS_PER_SEC);
        for (int i = 0; i < 133; i++)
            cout << "-";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;    
        for (int i = 0; i < 133; i++)
            cout << "-";
        cout<<"Time : "<<etime<<" seconds";    
        cout << endl;   

    }
}
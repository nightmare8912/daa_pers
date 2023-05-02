#include<iostream>
#include<time.h>
using namespace std;
int partition(int arr[],int lb,int ub){
    int pivot=arr[lb];
    int start=lb, end = ub;
    while(start < end){
        while( arr[start] <= pivot)
            start++;
        while(arr[end]>pivot)
            end--;
        if(start<end)
            swap(arr[start],arr[end]);        
    }
    swap(arr[lb],arr[end]);
    return end;
}
void quickSort(int arr[],int lb, int ub){
    if(ub>lb){
        int m=partition(arr,lb,ub);
        quickSort(arr,lb,m-1);
        quickSort(arr,m+1,ub);
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
        quickSort( arr, 0, n);
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
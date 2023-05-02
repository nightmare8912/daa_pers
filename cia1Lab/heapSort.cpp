#include<iostream>
#include<time.h>
using namespace std;
void maxHeapify(int arr[],int parent, int heapSize){
    int left, right, largest;
    left = 2 * parent + 1;
    right = 2 * parent + 2;
    largest = parent;
    if(left < heapSize && arr[left] > arr[largest])
        largest = left;
    if(right < heapSize && arr[right] > arr[largest])
        largest = right;
    if(largest != parent)
    {
        swap(arr[parent], arr[largest]);
        maxHeapify(arr, largest, heapSize);
    }        
}
void buildHeap(int arr[],int heapSize){
    for(int i = (heapSize/2)-1; i >= 0; i--){
        maxHeapify(arr , i, heapSize);
    }
}
void heapSort(int arr[],int heapSize){
    buildHeap(arr , heapSize);
    for(int i = heapSize-1; i>0; i--){
        swap(arr[0],arr[i]);
        //heapSize--;
        maxHeapify(arr, 0 ,i);
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
        for (int i = 1; i <= n; i++)
        {
            arr[i] = rand() % 20;
            cout << arr[i] << " ";
        }
        cout << endl;
        st = clock();
        heapSort( arr , n );
        end = clock();
        etime=((double)(end-st)/CLOCKS_PER_SEC);
        for (int i = 0; i < 133; i++)
            cout << "-";
        cout << endl;
        for (int i = 1; i <= n; i++)
            cout << arr[i] << ", ";
        cout << endl;    
        for (int i = 0; i < 133; i++)
            cout << "-";
        cout<<"Time : "<<etime<<" seconds";    
        cout << endl;   

    }
}
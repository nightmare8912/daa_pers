#include<iostream>
using namespace std;
void minHeapify(char arr[], int i, int heapSize){
    int left, right, smallest;
    left = 2*i;
    right = 2*i + 1;
    smallest = i;
    if(left <= heapSize && arr[left] < arr[smallest])
        smallest = left;
    if(right <= heapSize && arr[right] < arr[smallest])
        smallest = right;
    if(smallest != i){
        swap(arr[i], arr[smallest]);
        minHeapify(arr,smallest,heapSize);
    }        
}
void buildHeap(char arr[],int heapSize){
    for(int i = heapSize/2; i >= 1; i--)
        minHeapify(arr, i, heapSize);
}
void heapSort(char arr[], int heapSize){
    buildHeap(arr, heapSize);
    for(int i = heapSize; i>= 1; i--){
        swap(arr[1], arr[i]);
        buildHeap(arr, --heapSize);
    }
}
int main(){
    for(;;){
        int n;
        cout<<"Enter n: ";
        cin>>n;
        char arr[n];
        for(int i = 1; i <= n; i++){
            int temp = rand()%123;
            if(temp<97)
                i--;
            else
                arr[i]=temp;    
        }
        for(int i=1; i <=n; i++)
            cout<<arr[i]<<" ";
        cout<<"\n-----------------\n";
        heapSort(arr, n);
        for(int i=1; i <=n; i++)
            cout<<arr[i]<<" ";
        cout<<"\n-----------------\n";    
    }
}
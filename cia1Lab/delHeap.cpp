#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;
void maxheap(int arr[],int i,int n){
int largest=i;
int left=2*i+1;
int right=2*i+2;
if(left<n && arr[left]>arr[largest]){
largest=left;
}
if(right<n && arr[right]>arr[largest]){
largest=right;
}
 if(largest!=i){
swap(arr[largest],arr[i]);
maxheap(arr,largest,n);

}
}
void heapsort(int arr[],int n){
for(int i=n/2-1;i>=0;i--){
maxheap(arr,i,n);
}
for(int i=n-1;i>0;i--){
swap(arr[0],arr[i]);
maxheap(arr,0,i);
}

}
int main(){

cout<<"Enter n: ";
cin>>n;
int arr[n];
cout<<"Before sorting: "<<endl;
for(int i=0;i<n;i++){
arr[i]=rand()%50;
cout<<arr[i]<<" ";
}
cout<<endl;
//int arr[]={9,8,11,12,4,3};
//int n=sizeof(arr)/sizeof(arr[0]);
heapsort(arr,n);
for(int i=0;i<n;i++){
cout<<arr[i]<<" ";
}
return 0;
}

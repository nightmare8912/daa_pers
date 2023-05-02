#include<iostream>
#include<time.h>
using namespace std;
class returnType{
    public:
    int low, value, high;
    returnType(int a, int b, int c){
        low = a;
        high = b;
        value = c;
    }
};
returnType maxCrossSubarray(int arr[], int low, int mid, int high)
{
    int leftSum = -9999999, rightSum = -9999999,sum, maxLeft, maxRight;
    sum=0;
    for(int i = mid; i>=0; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
        {
            leftSum = sum;
            maxLeft = i;
        }
    }

    sum = 0;
    for(int i = mid+1; i<=high; i++){
        sum += arr[i];
        if(sum > rightSum)
        {
            rightSum = sum;
            maxRight = i;
        }
    }

    returnType r(maxLeft, maxRight, leftSum + rightSum);
    return r;
}
returnType maxSumSubarray(int arr[], int low, int high)
{
    
    if ( high == low)
    {
        returnType r(low,high,arr[low]);
        return r;
    }
        
    else
    {
        int mid = (low + high)/2;
        returnType r1 = maxSumSubarray(arr, low, mid);
        returnType r2 = maxSumSubarray(arr, mid+1, high);
        returnType r3 = maxCrossSubarray(arr, low, mid, high);

        if(r1.value >= r2.value && r1.value >= r3.value)
           return r1;
        else if(r2.value >= r1.value && r2.value >= r3.value)
            return r2;
        else
            return r3;        
    }
}
int main()
{
    // clock_t st,end;
    // double etime;
    // srand((long int)clock());
    for (;;)
    {
        int n;
        cout << "Enter n: ";
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 19 + (-8); 
            cout << arr[i] << " ";
        }
        cout << endl;
        // st = clock();
        returnType r=maxSumSubarray( arr, 0, n-1);
        cout<<"Low: "<<r.low<<"\nHigh: "<<r.high<<"\nMax-Sum: "<<r.value<<endl;
        // end = clock();
        // etime=((double)(end-st)/CLOCKS_PER_SEC);
        for (int i = 0; i < 133; i++)
            cout << "-";
        cout << endl;
        // for (int i = 0; i < n; i++)
        //     cout << arr[i] << " ";
        cout << endl;    
        for (int i = 0; i < 133; i++)
            cout << "-";
        // cout<<"Time : "<<etime<<" seconds";    
        cout << endl;   

    }
}
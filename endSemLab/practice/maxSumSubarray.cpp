#include <iostream>
#include <time.h>
#define INT_MIN -99999
using namespace std;

struct returnType
{
    int low, high, value;
};

returnType FMCS(int arr[], int low, int mid, int high)
{
    int sum = 0;
    int left_sum ,right_sum;
    left_sum = right_sum = INT_MIN;
    returnType r;
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            r.low = i;
        }
    }

    sum = 0;

    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > right_sum)
        {
            right_sum = sum;
            r.high = i;
        }
    }

    r.value = left_sum + right_sum;
    return r;
}

returnType FMS(int arr[], int low, int high)
{
    returnType rv;
    if (low == high)
    {
        rv.low = low;
        rv.high = high;
        rv.value = arr[low];
    }

    else
    {
        int mid = (low + high) / 2;
        returnType left, right, cross;

        left = FMS(arr, low, mid);
        right = FMS(arr, mid + 1, high);
        cross = FMCS(arr, low, mid, high);

        rv = left;

        if (rv.value < right.value)
            rv = right;
        if (rv.value < cross.value)
            rv = cross;
    }
    return rv;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    srand((long int)clock());
    int arr[n  + 1];
    for (int i = 1; i <= n; i++)
    {
        arr[i] = rand() % 30 - 15;
        cout << arr[i] << " ";
    }
    cout << endl;
    returnType res = FMS(arr, 1, n);
    cout << "MAX SUM: " << res.value << endl;
    cout << "LOW: " << res.low << endl;
    cout << "HIGH: " << res.high << endl;
}
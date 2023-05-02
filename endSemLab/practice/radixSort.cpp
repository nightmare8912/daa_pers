#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

int getDigit(int x, int n)
{
    int d, y;
    y = x / pow(10, n - 1);
    d = x % 10;
    return d;
}

void countSort(int a[], int b[], int n, int k, int d)
{
    int c[k + 1], s;

    for (int i = 0; i <= k; i++)
        c[i] = 0;
    
    for (int j = 1; j <= n; j++)
    {
        s = getDigit(a[j], a);
    }
}
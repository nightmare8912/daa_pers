#include <iostream>
#include <time.h>
#define INT_MAX 999999
using namespace std;

int recMCM(int *p, int i, int j)
{
    if (i == j)
        return 0;
    int min = INT_MAX;
    int temp;

    for (int k = i; k < j; k++)
    {
        temp = recMCM(p, i, k) + recMCM(p, k + 1, j) + p[i - 1] * p[k] *p[j];
        if (temp < min)
            min = temp;
    }
    return min;
}

int dpMCM(int *p, int n, int **m, int **s)
{
    for (int i = 0; i <= n; i++)
        m[i][i] = 0; 
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {   
                int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] *p[j];
                if (temp < m[i][j])
                {
                    m[i][j] = temp;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n];
}

void printOptimal(int **s, int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        printOptimal(s, i, s[i][j]);
        printOptimal(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    int n;
    time_t st, end;
    double etime;
    cout << "Enter number of matrices: ";
    cin >> n;
    int p[n + 1];
    cout << "\nMatrix Dimensions: \t";
    for (int i = 0; i <= n; i++)
    {
        p[i] = (rand() % n) + 2;
        cout << p[i] << "\t";
    }
    int **m, **s;
    m = new int*[n + 1];
    s = new int*[n + 1];
    for (int i = 0; i <= n; i++)
    {
        m[i] = new int[n + 1];
        s[i] = new int[n + 1];
    }
    st = clock();
    cout << "\nMin multi(DP): " << dpMCM(p, n, m, s) << "\n";
    end = clock();
    etime = (double)(end - st)/CLOCKS_PER_SEC;
    cout << "\nTime : " << etime << " seconds."<< endl;
    printOptimal(s, 1, n);
    st = clock();
    cout << "\n\nMin multi(Brute Force): " << recMCM(p, 1, n);
    end = clock();
    etime = (double)(end - st)/CLOCKS_PER_SEC;
    cout << "\nTime : " << etime << " seconds." <<endl;
}
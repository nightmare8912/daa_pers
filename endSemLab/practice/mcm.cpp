#include <iostream>
#include <time.h>
#define INT_MAX 99999
using namespace std;

int recMCM(int p[], int i, int j)
{
    if (i == j)
        return 0;
    
    int min = INT_MAX, q;

    for (int k = i; k < j; k++)
    {
        q = recMCM(p, i, k) + recMCM(p, k + 1, j) + p[i - 1] * p[j] * p[k];
        if (q < min)
            min = q;
    }
    return min;
}

int dpMCM(int p[], int n, int **m, int **s)
{
    for (int i = 0; i <= n; i++)
        m[i][i] = 0;

    for (int len = 2; len <= n; len ++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
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
    {
        cout << "A" << i;
        return;
    }
    cout << "(";
    printOptimal(s, i, s[i][j]);
    printOptimal(s, s[i][j] + 1, j);
    cout << ")";
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    srand((long int)clock());
    int p[n + 1];
    cout << "Dimension array: " << "\n";
    for (int i = 0; i <= n; i++)
    {
        p[i] = rand() % 10 + 2;
        cout << p[i] << " "; 
    }
    cout << "\n";
    cout << "Min multi(using rec): " << recMCM(p, 1, n);

    int **m, **s;

    m = new int*[n + 1];
    s = new int*[n + 1];

    for (int i = 0; i <= n; i++)
    {
        m[i] = new int[n + 1];
        s[i] = new int[n + 1];
    }

    cout << "\n";
    cout << "Min multi(using dp): " << dpMCM(p, n, m, s);
    cout << "\n";
    printOptimal(s, 1, n);
}
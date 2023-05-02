#include <iostream>
#include <time.h>
#define INT_MAX 99999
using namespace std;

long int cnt = 0;

int recMCM(int *p, int i, int j)
{
    if (i == j)
        return 0;
    
    int min = INT_MAX, temp;
    for (int k = i; k < j; k++)
    {
        cnt++;
        temp = recMCM(p, i, k) + recMCM(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (temp < min)
            min = temp;
    }
    return min;
}

int dpMCM(int *p, int n, int **m, int **s)
{
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                cnt++;
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
    cout << "Enter number of matrices: ";
    cin >> n;

    // srand((long int)clock());
    int p[n + 1];
    cout << "Dim array: \n";
    for (int i = 0; i < n + 1; i++)
    {
        // p[i] = (rand() % n) + 2;
        // cout << p[i] << " ";
        cin >> p[i];
    }
        
    cout << endl;
    int min = recMCM(p, 1, n);
    cout << "Using Brute Force\n";
    cout << "Min multi : " << min << "\n";
    cout << "Active operations : " << cnt << "\n";
    cnt = 0;

    int **m, **s;

    m = new int *[n + 1];
	s = new int *[n + 1];

	for (int i = 0; i < n + 1; i++)
	{
		m[i] = new int[n + 1];
		s[i] = new int[n + 1];
	}

    min = dpMCM(p, n, m, s);
    cout << "Using DP\n";
    cout << "Min multi : " << min << "\n";
    cout << "Active operations : " << cnt << "\n"; 
    printOptimal(s, 1, n);
}
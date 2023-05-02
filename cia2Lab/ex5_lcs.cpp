#include <iostream>
#define MAX_SIZE 100

using namespace std;

struct ReturnType
{
    int b[MAX_SIZE][MAX_SIZE];
    char c[MAX_SIZE][MAX_SIZE];
};

ReturnType lcsLength(char x[], char y[], int m, int n)
{
    ReturnType r;
    for (int i = 0; i <= m; i++)
        r.c[i][0] = 0;
    for (int j = 0; j <= n; j++)    
        r.c[0][j] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == y[j])
            {
                r.c[i][j] = r.c[i-1][j-1] + 1;
                r.b[i][j] = '/';
            }
            else if (r.c[i - 1][j] >= r.c[i][j-1])
            {
                r.c[i][j] = r.c[i - 1][j];
                r.b[i][j] = '|';
            }
            else
            {
                r.c[i][j] = r.c[i][j-1];
                r.b[i][j] = '-';
            }
        }
    }
    return r;
}
void printLCS(ReturnType r, char x[],int i, int j)
{
    if (i == 0 || j == 0)
        return;
    else if (r.b[i][j] == '/')
    {
        printLCS(r, x, i - 1, j - 1);
        cout << x[i];
    }
    else if (r.b[i][j] == '|')
        printLCS(r, x, i - 1, j);
    else
        printLCS(r, x, i, j - 1);    
} 

int recLCS(char x[], char y[], int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    else if (x[m - 1] == y[n - 1])
        return 1 + recLCS(x, y, m - 1, n - 1);
    else
        return max(recLCS(x, y, m, n - 1), recLCS(x, y, m - 1, n));
}

int main()
{
    int m, n;
    cout << "Enter the length of first string: ";
    cin >> m;
    char x[m];
    cout << "Enter the string: ";
    for (int i = 1; i <= m; i++)
        cin >> x[i];
    cout << "Enter the length of the second string: ";
    cin >> n;
    char y[n];
    cout << "Enter the string: ";
    for (int j = 1; j <= n; j++)
        cin >> y[j];
    ReturnType r = lcsLength(x, y, m, n);
    printLCS(r, x, m, n);
    cout << "\nLCS length : " << r.c[m][n];
    cout << "\nLCS length using brute force: " << recLCS(x, y, m + 1 ,n + 1);
}
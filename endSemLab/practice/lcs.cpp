#include <iostream>
using namespace std;

int recLCS(char x[], char y[], int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    
    if (x[m - 1] == y[n - 1])
        return 1 + recLCS(x, y, m - 1, n - 1);

    return max(recLCS(x, y, m - 1, n), recLCS(x, y, m, n - 1));
}

void dpLCS(char x[], char y[], int **b, string **c ,int m, int n)
{
    for (int i = 0; i <= m; i++)
        b[i][0] = 0;
    
    for (int j = 0; j <= n; j++)
        b[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == y[j])
            {
                b[i][j] = b[i - 1][j - 1] + 1;
                c[i][j] = "TL";
            }

            else if (b[i - 1][j] >= b[i][j - 1])
            {
                b[i][j] = b[i - 1][j];
                c[i][j] = "T";
            }

            else 
            {
                b[i][j] = b[i][j - 1];
                c[i][j] = "L";
            }
        }
    }
}

void printLCS(char x[], string **c, int m, int n)
{
    if (m == 0 || n == 0)
        return;
    
    if (c[m][n] == "TL")
    {
        printLCS(x, c, m - 1, n - 1);
        cout << x[m];
    }

    else if (c[m][n] == "T")
        printLCS(x, c, m - 1, n);

    else
        printLCS(x, c, m, n - 1);
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
    // ReturnType r = lcsLength(x, y, m, n);
    // printLCS(r, x, m, n);
    // cout << "\nLCS length : " << r.c[m][n];
    cout << "\nLCS length using brute force: " << recLCS(x, y, m + 1 ,n + 1);

    int **b;
    string **c;

    b = new int*[n + 1];
    c = new string*[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        b[i] = new int[n + 1];
        c[i] = new string[n + 1];
    }

    cout << "\nLCS length: ";
    dpLCS(x, y, b, c, m ,n); 
    cout << b[m][n] << "\n\n";
    printLCS(x,c, m, n);
}
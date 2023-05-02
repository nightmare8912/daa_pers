#include <iostream>
using namespace std;

bool areEqual(char x[], char y[], int st_index, int size)
{
    for (int i = 1, j = st_index; i <= size; i++, j++)
    {
        if (x[j] != y[i])
            return false;
    }
    return true;    
}

void naiveMatcher(char txt[], char pat[], int n, int m)
{
    bool flag = false;
    for (int s = 0; s <= n - m; s++)
    {
        if (areEqual(txt, pat, s + 1, m))
        {
            cout << "Pattern occurs with shift " << s << endl;
            flag = true;
        } 
    }
    if (!flag)
        cout << "Pattern could not be found" << endl;
}

int main()
{
    int m, n;
    cout << "Enter length of text: ";
    cin >> n;
    char txt[n + 1];
    cout << "Enter the text: ";
    for (int i = 1; i <= n; i++)
        cin >> txt[i];
    for (int i = 1; i <= n; i++)
        cout << txt[i];
    cout << endl;
    cout << "Enter length of pattern: ";
    cin >> m;
    char pat[m + 1];
    cout << "Enter the pattern: ";
    for (int i = 1; i <= m; i++)
        cin >> pat[i];
    for (int i = 1; i <= m; i++)
        cout << pat[i];
    cout << endl;
    naiveMatcher(txt, pat, n , m);
}
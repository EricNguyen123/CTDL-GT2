#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int c, n;
    cin >> c >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int b[n + 1][c + 1];
    for(int i = 0; i <= c; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            b[j][i] = 0;
        }
    }
    for(int i= 1; i <= n; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(j <= a[i - 1]) b[i][j] = b[i - 1][j];
            else b[i][j] = max(b[i - 1][j - a[i - 1]] + a[i - 1], b[i - 1][j]);
        }
    }
    cout << b[n][c] << endl;
    return 0;
}
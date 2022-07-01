#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n + 2][m + 2];
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        a[0][0] = 0;
        for(int i = 1; i <= n; i++)
        {
            a[i][0] = INT_MAX;
        }
        for(int i = 1; i <= m; i++)
        {
            a[0][i] = INT_MAX;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                int Min;
                Min = min(a[i - 1][j - 1], min(a[i - 1][j], a[i][j - 1]));
                a[i][j] += Min;
            }
        }
        cout << a[n][m] << endl;
    }
    return 0;
}
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
        int a[n + 1][m + 1];
        int d[n + 1][m + 1];
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                d[i][j] = a[i][j];
            }
        }
        for(int i = 0; i <= n; i++)
        {
            a[i][0] = 0;
        }
        for(int i = 0; i <= m; i++)
        {
            a[0][i] = 0;
        }
        int result = INT_MIN;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(!a[i][j]) continue;
                if(!a[i][j - 1] || !a[i - 1][j] || !a[i - 1][j - 1]) continue;
                d[i][j] = min(d[i][j - 1], min(d[i - 1][j], d[i - 1][j - 1]));
                d[i][j]++;
                result = max(result, d[i][j]);
            }
        }
        cout << result << endl;
    }
    return 0;
}
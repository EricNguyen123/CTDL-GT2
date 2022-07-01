#include<iostream>
#include<vector>
using namespace std;
int n, m, a[15][15], b[15], c[15], d;
void ReInit()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            a[i][j] = 0;
        }
        c[i] = 0;
    }
    d = 0;
}
void hamilton(int *b, int *c, int i)
{
    for(int j = 1; j <= n; j++)
    {
        if(a[b[i - 1]][j] == 1 && c[j] == 0)
        {
            b[i] = j;
            c[j] = 1;
            if(i < n) hamilton(b, c, i + 1);
            if(i == n - 1)
            {
                int g = 0;
                for(int l = 2; l <= n; l++)
                {
                    if(c[l] == 0)
                    {
                        g = 1;
                        break;
                    }
                }
                if(g == 0) d = 1;
            }
            c[j] = 0;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        ReInit();
        for(int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            a[u][v] = 1;
            a[v][u] = 1;
        }
        b[0] = 1;
        hamilton(b, c, 1);
        cout << d << endl;
    }
    return 0;
}
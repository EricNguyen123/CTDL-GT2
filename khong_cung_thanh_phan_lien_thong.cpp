#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >list(1000);
int xet[1000];
void DFS(int u)
{
    xet[u] = 1;
    for(int i = 0; i < list[u].size(); i++)
    {
        if(xet[list[u][i]] == 0)
        {
            DFS(list[u][i]);
        }
    }
}
int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    for(int i = 1; i <= n; i++)
    {
        xet[i] = 0;
        list[i].clear();
    }
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    DFS(x);
    int d = 0;
    for(int i = 1; i <= n; i++)
    {
        if(xet[i] == 0)
        {
            cout << i << endl;
            d = 1;
        }
    }
    if(d == 0) cout << 0 << endl;
    return 0;
}
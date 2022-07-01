#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
int n;
vector<vector<int> > list(1005);
bitset<1005>bs;
int sau[1005];
void ReInit()
{
    for(int i = 1; i <= n; i++) 
    {
        bs[i] = 0;
        sau[i] = 0;
    }
}
void DFS(int u)
{
    bs[u] = 1;
    for(int i = 0; i < list[u].size(); i++)
    {
        if(bs[list[u][i]] == 0 && sau[u] == 0)
        {
            sau[u] = list[u][i];
            DFS(list[u][i]);
        }
    }
}
int KiemTraChuTrinh(int u)
{
    int v = u;
    while(sau[u] != 0)
    {
        u = sau[u];
    }
    if(v == u) return 1;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++) list[i].clear();
        int m = n - 1;
        while(m--)
        {
            int u, v;
            cin >> u >> v;
            list[u].push_back(v);
            list[v].push_back(u);
        }
        int d = 0;
        for(int i = 1; i <= n; i++)
        {
            ReInit();
            DFS(i);
            if(KiemTraChuTrinh(i) == 1)
            {
                cout << "NO" << endl;
                d = 1;
                break;
            }
        }
        if(d == 0) cout << "YES" << endl;
    }
    return 0;
}
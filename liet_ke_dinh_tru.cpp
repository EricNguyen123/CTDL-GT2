#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >list(1005);
vector<int>xet(1005);
void ReInit(int n)
{
    for(int i = 1; i <= n; i++)
    {
        xet[i] = 0;
    }
}
int check(int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(xet[i] == 0) return 0;
    }
    return 1;
}
void DFS(int u)
{
    xet[u] = 1;
    for(int i = 0; i < list[u].size(); i++)
    {
        if(!xet[list[u][i]])
        {
            xet[list[u][i]] = 1;
            DFS(list[u][i]);
        }
    }
}
void DinhTru(int n)
{
    for(int i = 1; i <= n; i++)
    {
        ReInit(n);
        xet[i] = 1;
        if(i == 1) DFS(2);
        else DFS(1);
        if(!check(n))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
            list[i].clear();
        }
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            list[u].push_back(v);
            list[v].push_back(u);
        }
        DinhTru(n);
    }
    return 0;
}
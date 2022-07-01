#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >list(1005);
vector<int>xet(1005);
void DFS(int u)
{
    xet[u] = 1;
    for(int i = 0; i < list[u].size(); i++)
    {
        if(xet[list[u][i]] == 0)
        {
            xet[list[u][i]] = 1;
            DFS(list[u][i]);
        }
    }
}
void ReInit(int n)
{
    for(int  i = 1; i <= n; i++)
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
int checklienthongmanh(int n)
{
    for(int i = 1; i <= n; i++)
    {
        ReInit(n);
        DFS(i);
        if(check(n) == 0) return 0;
    }
    return 1;
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
        for(int  i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            list[u].push_back(v);
        }
        if(checklienthongmanh(n) == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >list(1005);
vector<int>xet(1005);
vector<int>truoc(1005);
void ReInit(int n)
{
    for(int i = 1; i <= n; i++)
    {
        xet[i] = 0;
        truoc[i] = 0;
    }
}
void DFS(int u)
{
    xet[u] = 1;
    for(int i = 0; i < list[u].size(); i++)
    {
        if(!xet[list[u][i]])
        {
            truoc[list[u][i]] = u;
            DFS(list[u][i]);
        }
    }
}
int KTLienthong(int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(!xet[i]) return 0;
    }
    return 1;
}
int KTChutrinh(int n, int u, int en)
{
    if(truoc[en] == u) return 0;
    for(int i = 0; i < list[en].size(); i++)
    {
        if(list[en][i] == u) return 1;
    }
    return 0;
}
void duyet(int n)
{
    for(int i = 1; i <= n; i++)
    {
       for(int j = i + 1; j <= n; j++)
       {
            ReInit(n);
            DFS(i);
            if(KTChutrinh(n, i, j))
            {
                cout << "YES" << endl;
                return;
            }
       }
        
    }
    cout << "NO" << endl;
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
        duyet(n);
    }
    return 0;
}
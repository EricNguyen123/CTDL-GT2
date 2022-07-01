#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, st, en;
vector<vector<int> >list;
vector<int>truoc;
vector<bool>xet;
void Reinit()
{
    for(int i = 1; i <= n; i++)
    {
        xet[i] = false;
        truoc[i] = 0;
    }
}
void DFS(int u)
{
    xet[u] = true;
    for(int i = 0; i < list[u].size(); i++)
    {
        if(!xet[list[u][i]])
        {
            truoc[list[u][i]] = u;
            DFS(list[u][i]);
        }
    }
}
void BFS(int u)
{
    queue<int>q=queue<int>();
    q.push(u);
    xet[u] = true;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int i = 0; i < list[v].size(); i++)
        {
            if(!xet[list[v][i]])
            {
                q.push(list[v][i]);
                truoc[list[v][i]] = v;
                xet[list[v][i]] = true;
            }
        }
    }
}
void KiemTraDD()
{
    if(truoc[en] == 0) cout << -1 << endl;
    else{
        stack<int>s=stack<int>();
        s.push(en);
        int j = en;
        while(truoc[j] != st)
        {
            s.push(truoc[j]);
            j = truoc[j];
        }
        s.push(st);
        while(!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> st >> en;
        list.resize(n + 1);
        truoc.resize(n + 1);
        xet.resize(n + 1);
        Reinit();
        int u, v;
        for(int i = 0; i < m; i++)
        {
            cin >> u >> v;
            list[u].push_back(v);
            list[v].push_back(u);
        }
        for(int i = 1; i <= n; i++)
        {
            sort(list[i].begin(), list[i].end());
        }
        //DFS(st);
        BFS(st);
        KiemTraDD();
        list.clear();
        truoc.clear();
        xet.clear();
    }
    return 0;
}
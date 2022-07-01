#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
vector<vector<int> >list;
vector<int>truoc;
int xet[100005];
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
void BFS(int u)
{
    queue<int>q=queue<int>();
    q.push(u);
    xet[u] = 1;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i = 0; i < list[u].size(); i++)
        {
            if(!xet[list[u][i]])
            {
                q.push(list[u][i]);
                truoc[list[u][i]] = u;
                xet[list[u][i]] = 1;
            }
        }
    }
}

void DD(int s, int t)
{
    if(truoc[t] == 0) 
    {
        cout << -1 << endl;
    }
    else{
        int j = t;
        stack<int>q = stack<int>();
        q.push(j);
        while(truoc[j] != s)
        {
            q.push(truoc[j]);
            j = truoc[j];
        }
        q.push(s);
        while(!q.empty())
        {
            cout << q.top() << " ";
            q.pop();
        }
        cout << endl;
    }
    
}
int XetDD(int s, int t)
{
    if(truoc[t] == 0) 
    {
        return 0;
    }
    else{
        return 1;
    }
    
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        list.resize(n + 1);
        truoc.resize(n + 1);
        for(int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            list[u].push_back(v);
            list[v].push_back(u);
        }
        for(int i = 1; i <= n; i++)
        {
            sort(list[i].begin(), list[i].end());
            xet[i] = 0;
            truoc.push_back(0);
        }
        truoc.push_back(0);
        //DFS(s);
        BFS(s);
        DD(s, t);
        // int q;
        // cin >> q;
        // for(int i = 0; i < q; i++)
        // {
        //     truoc.clear();
        //     for(int i = 0; i <= n; i++)
        //     {
        //         truoc.push_back(0);
        //         xet[i] = 0;
        //     }
        //     cin >> s >> t;
        //     DFS(s);
        //     if(XetDD(s, t) == 0) cout << "NO" << endl;
        //     else cout << "YES" << endl;
        // }
        
        list.clear();
        truoc.clear();
    }
    return 0;
}
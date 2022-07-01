#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >list;
int KiemTraDDEuler(int n)
{
    int d = 0;
    for(int i = 1; i <= n; i++)
    {
        if(list[i].size() % 2 != 0) d++;
    }
    if(d == 2) return 1;
    return 0;
}
int KiemTraEuler_Cycle(int n)
{
    int d = 0;
    for(int i = 1; i <=n; i++)
    {
        if(list[i].size() % 2 != 0) d++;
    }
    if(d > 0) return 0;
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
        list.resize(n + 1);
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            list[u].push_back(v);
            list[v].push_back(u);
        }
        if(KiemTraEuler_Cycle(n) == 1)
        {
            cout << 2 << endl;
        }
        else{
            if(KiemTraDDEuler(n) == 1) cout << 1 << endl;
            else cout << 0 << endl;
        }
        list.clear();
    }
    return 0;
}
#include<iostream>
using namespace std;
int Root[100005], Size[100005];
int n, m;

inline int findRoot(int x)
{
    if(x == Root[x])
        return x;
    return Root[x] = findRoot(Root[x]);
}

inline void Union(int x, int y)
{
    int rootX = findRoot(x), rootY = findRoot(y);
    if(rootX != rootY)
    {
        if(Size[rootX] < Size[rootY])
            swap(rootX, rootY);
        Root[rootY] = rootX;
        Size[rootX] += Size[rootY];
    }
}

int main()
{
    int t, x, y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i)
        {
            Root[i] = i;
            Size[i] = 1;
        }
        int MAX = -1;
        while(m--)
        {
            cin >> x >> y;
            Union(x, y);
        }
        for(int i = 1; i <= n; ++i)
            MAX = max(MAX, Size[Root[i]]);
        cout << MAX << endl;
    }
    return 0;
}

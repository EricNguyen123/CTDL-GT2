#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<climits>
using namespace std;
vector<map<int, int> > dp;

bool check(int mid, int x, int y)
{
    map<int, int >::iterator it = dp[mid].lower_bound(x);
    if(it == dp[mid].begin())
        return 0;
    it--;
    return (*it).second < y;
}

void Add(int l, int x, int y)
{
    map<int, int>::iterator it = dp[l].lower_bound(x);
    map<int, int>::iterator ori = it;
    while(it != dp[l].end() and (*it).second >= y)
        it++;
    dp[l].erase(ori, it);
    dp[l].insert(make_pair(x, y));
}

int main()
{
    int n, x, y, res = 0, l, r, mid;
    cin >> n;
    dp.resize(n);
    Add(0, INT_MIN, INT_MIN);
    while(n--)
    {
        cin >> x >> y;
        l = 0;
        r = res;
        while(l <= r)
        {
            mid = (l + r) >> 1;
            if (check(mid, x, y))
                l = mid + 1;
            else
                r = mid - 1;
        }
        if(res == l - 1)
            res = l;
        Add(l, x, y);
    }
    cout << res;
    return 0;
}
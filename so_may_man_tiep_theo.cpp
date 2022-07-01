#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    long long a, b;
    cin >> a >> b;
    queue<long long>q;
    q.push(4);
    q.push(7);
    vector<long long>v;
    v.push_back(4);
    v.push_back(7);
    while(q.front() <= 1e9)
    {
        long long s = q.front();
        q.push(s * 10 + 4);
        q.push(s * 10 + 7);
        v.push_back(s * 10 + 4);
        v.push_back(s * 10 + 7);
        q.pop();
    }
    long long res = 0;
    while(b >= a)
    {
        vector<long long>::iterator i;
        i = lower_bound(v.begin(),v.end(),a);
        long long c;
        c = min(*i, b);
        c = c - a + 1;
        res = res + c * (*i);
        a = *i + 1;
    }
    cout << res << endl;
    return 0;
}
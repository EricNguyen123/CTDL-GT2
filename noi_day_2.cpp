#include<iostream>
#include<queue>
#include<vector>
#define e 1000000007
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        priority_queue <long long, vector<long long>, greater<long long> > a;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push(x);
        }
        long long sum = 0;
        while(a.size() > 1)
        {
            int x, y;
            x = a.top();
            a.pop();
            y = a.top();
            a.pop();
            long long s = x + y;
            s %= e;
            a.push(s);
            sum += s;
            sum %= e;

        }
        //cout << a.size()<<endl;
        cout << sum << endl;
    }
    return 0;
}
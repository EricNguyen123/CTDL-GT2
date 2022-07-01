#include<iostream>
#include<algorithm>
using namespace std;
int n;
int k;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        int d[100005] = {};
        int e = 1000000007;
        d[0] = d[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= min(i, k); j++)
            {
                d[i] += d[i - j];
                d[i] %= e;
            }
        }
        cout << d[n] << endl;
    }
    return 0;
}
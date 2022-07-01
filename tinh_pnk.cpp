#include<iostream>
using namespace std;
long long mod = 1e9 + 7;

long long xuly(int dau, int cuoi)
{
    if(dau == cuoi) return dau;
    if(dau == cuoi - 1) return dau * cuoi % mod;
    int mid = (dau + cuoi) / 2;
    return xuly(dau, mid) * xuly(mid + 1, cuoi) % mod;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        if(k > n)
        {
            cout << 0 << endl;
            continue;
        }
        long long a = xuly(n - k + 1, n);
        cout << a << endl;
    }
    return 0;
}
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
long long gcd_extend(long long a, long long b, long long *x, long long *y)
{
    if(b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = gcd_extend(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}
long long modulo_inverse_euclidean(long long a, long long b)
{
    long long x, y;
    if(gcd_extend(a, b, &x, &y) != 1) return -1;
    return (x % b + b) % b; 
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        long long a = xuly(n - k + 1, n);
        long long b = xuly(1, k);
        long long c = modulo_inverse_euclidean(b, mod);
        long long d = (a * c) % mod;
        cout << d << endl;
    }
    return 0;
}
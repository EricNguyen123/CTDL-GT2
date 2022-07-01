#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        unsigned long long sum = 0;
        long long a[n], b[n];
        long long c[m];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        for(int i = 0; i < n; i++)
        {
            sum += a[i] * b[n - 1 - i];
        }
        cout << sum << endl;
    }
}
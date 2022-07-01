#include<iostream>
#include<algorithm>
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
        long long a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += a[i] * i;
            sum %= e;
        }
        cout << sum << endl;
    }
    return 0;
}
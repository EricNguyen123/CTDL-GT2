#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long x[5];
    x[0] = a[0] * a[1];
    x[1] = a[n - 2] * a[n - 1];
    x[2] = a[n - 3] * x[1];
    x[3] = x[0] * a[2];
    x[4] = x[0] * a[n - 1];
    long long Max = 0;
    for(int i = 0; i < 5; i++)
    {
        Max = max(Max, x[i]);
    }
    cout << Max << endl;
}
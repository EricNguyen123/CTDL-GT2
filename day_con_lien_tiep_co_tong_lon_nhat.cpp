#include<iostream>
#include<algorithm>
using namespace std;
void xuly(int *a, int n)
{
    int local = a[0];
    int result = a[0];
    for(int i = 1; i < n; i++)
    {
        local = max(local + a[i], a[i]);
        result = max(local, result);
    }
    cout << result << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i< n; i++)
        {
            cin >> a[i];
        }
        xuly(a, n);
    }
    return 0;
}
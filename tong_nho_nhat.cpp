#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        long long s, t;
        s = t = 0;
        for(int i = 0; i < n; i++)
        {
            if(i%2 == 0)
            {
                s = s * 10 + a[i];
            }
            else{
                t = t * 10 + a[i];
            }
        }
        cout << s + t << endl;
    }
}
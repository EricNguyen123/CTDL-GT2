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
        int b[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        int m = n / 2;
        int d = 0;
        for(int i = 0; i < m; i++)
        {
            if(a[i] != b[i])
            {
                if(a[i] == b[n - i - 1] && a[n - i - 1] == b[i])
                {
                    d = 0;
                }
                else{
                    d = 1;
                    break;
                }
            }
        }
        if(d == 0)
        {
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
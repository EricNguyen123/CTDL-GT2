#include<iostream>
#include<algorithm>
#include<climits>
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
        int Max = INT_MIN;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(a[j] < a[i])
                {
                    b[i] = max(b[i], b[j] + a[i]);
                }
            }
            Max = max(Max, b[i]);
        }
        cout << Max << endl;
    }
    return 0;
}
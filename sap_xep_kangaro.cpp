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
        int Count = n;
        int l = n >> 1, r = n - 1, mid = n >> 1;
        l--;
        while(l >= 0 && r >= mid)
        {
            if(a[r] >= a[l] << 1)
            {
                l--;
                r--;
                Count--;
            }
            else{
                l--;
            }
        }
        cout << Count << endl;
    }
    return 0;
}
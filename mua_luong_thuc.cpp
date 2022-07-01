#include<iostream>
#include<stdbool.h>
using namespace std;
inline int binSearch(int n, int m, int s)
{
    int res = -1, mid, l = 1, r = s;
    while(l <= r)
    {
        mid = (l + r) / 2;
        //cout << mid << endl;
        if((mid - mid / 7) * n >= s * m)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    if(res != -1) res -= res / 7;
    return res;
}

int main()
{
    int t = 1, n, m, s;
    cin >> t;
    while(t--)
    {
        cin >> n >> s >> m;
        cout << binSearch(n, m, s) << endl;
    }
    return 0;
}
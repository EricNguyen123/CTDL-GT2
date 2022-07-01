#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int x, y, z;
        cin >> x >> y >> z;
        int kt = 1;
        int d[n + 5];
        d[0] = 0;
        while(kt <= n)
        {
            d[kt] = d[kt - 1] + x;
            if(kt & 1)
            {
                d[kt] = min(d[kt], d[(kt + 1) / 2] + y + z);
            }
            else d[kt] = min(d[kt], d[kt / 2] + z);
            kt++;
        }
        cout << d[n] << endl;
    }
    return 0;
}
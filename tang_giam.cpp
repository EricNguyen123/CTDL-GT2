#include<iostream>
#include<algorithm>
using namespace std;
struct Cap
{
    double x, y;
};
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        Cap a[n];
        long b[n];
        long Max = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i].x >> a[i].y;
            b[i] = 1;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(a[j].x < a[i].x && a[j].y > a[i].y)
                {
                    b[i] = max(b[i], b[j] + 1);
                }
            }
            Max = max(Max, b[i]);
        }
        cout << Max << endl;
    }
    return 0;
}
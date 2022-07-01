#include<iostream>
#include<algorithm>
#include<stdbool.h>
using namespace std;
struct BeEn
{
    int s;
    int f;
};
bool check(BeEn a, BeEn b)
{
    return a.f < b.f;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        BeEn a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i].s;
        }
        for(int i = 0; i < n; i++)
        {
            cin >> a[i].f;
        }
        sort(a, a + n, check);
        int d = 1;
        int lcf = a[0].f;
        for(int i = 1; i < n; i++)
        {
            if(a[i].s >= lcf)
            {
                lcf = a[i].f;
                d++;
            }

        }
        cout << d << endl;
    }
}
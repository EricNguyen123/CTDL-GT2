#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector <int> a (n);
        vector <int> b (m);
        vector <int> c (n + m); 
        for(int i = 0; i < n; i++)
        {
           cin >> a[i];
        }
        for(int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
        cout << c[k - 1] << endl;
    }
    return 0;
}
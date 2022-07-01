#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, res = 0;
        cin >> n;
        int dd[30] = {};
        string s;
        cin >> s;
        for(int i = 0; i < s.size(); i++) dd[s[i] - 'A']++;
        for(int i = 0; i < 26; i++) res = max(res, dd[i]);
        int k = s.size() - (n - 1) * (res - 1);
        if(res <= k) cout << 1;
        else cout << -1;
        cout << endl;
    }
    return 0;
}
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    vector<string>s;
    queue<int>x;
    for(int i = 1; i <= 1e4; i++)
    {
        int a = i;
        while(a)
        {
            x.push(a & 1);
            a >>= 1;
        }
        string b = "";
        while(!x.empty())
        {
            b = char(x.front() + '0') + b;
            x.pop();
        }
        s.push_back(b);
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
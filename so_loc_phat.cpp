#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        queue<string>v;
        vector<string>s;
        v.push("6");
        v.push("8");
        s.push_back("6");
        s.push_back("8");
        int n;
        cin >> n;
        int f = 0;
        while(s[s.size() - 1].size() < n)
        {
            int d = s.size();
            while (!v.empty())
            {
                for(int i = f; i < d; i++)
                {
                    s.push_back(v.front() + s[i]);
                }
                v.pop();
            }
            f = d;
            v.push("6");
            v.push("8");
        }
        for(int i = s.size() - 1; i >= 0; i--) cout << s[i] << " ";
        cout << endl;
    }
    return 0;
}
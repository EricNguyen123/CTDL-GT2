#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        stack<char>v;
        int res = 0;
        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(v.empty())
            {
                v.push(s[i]);
                count = 0;
            }
            else if(v.top() == '[' && s[i] == ']')
            {
                v.pop();
                count += 2;
            }
            else if(v.top() == ']' && s[i] == '[')
            {
                res += v.size() + count;
                v.pop();
            }
            else if(v.top() == ']' && s[i] == ']')
            {
                v.push(s[i]);
            }
            else if(s[i] == '[')
            {
                v.push(s[i]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
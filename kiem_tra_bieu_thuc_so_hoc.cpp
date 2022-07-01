#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin, s);
        stack<char>v;
        int d = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ')')
            {
                d = 0;
                char x = v.top();
                v.pop();
                while(x != '(')
                {
                    if(x == '+' || x == '-' || x == '*' || x == '/') d = 1;
                    x = v.top();
                    v.pop();
                }
                if(d == 0) break;
            }
            else v.push(s[i]);
        }
        if(d == 0) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
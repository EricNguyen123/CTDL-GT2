#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        stack<char>st = stack<char>();
        string s;
        cin >> s;
        int d = 0;
        for(int i = 0; i < s.size();i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else if(s[i] == ')')
            {
                if(st.empty())
                {
                    d = 1;
                    break;
                }
                else if(st.top() == '(') st.pop();
                else {
                    d = 1;
                    break;;
                }
            }
            else if(s[i] == ']')
            {
                if(st.empty())
                {
                    d = 1;
                    break;
                }
                else if(st.top() == '[') st.pop();
                else {
                    d = 1;
                    break;;
                }
            }
            else{
                if(st.empty())
                {
                    d = 1;
                    break;
                }
                else if(st.top() == '{') st.pop();
                else {
                    d = 1;
                    break;;
                }
            }
        }
        if(d == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
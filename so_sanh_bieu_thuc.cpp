#include<iostream>
#include<stack>
using namespace std;
string chuanhoa(string s)
{
        stack<char>a=stack<char>();
        stack<char>b=stack<char>();
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ')')
            {
                a.push(s[i]);
            }
            else{
                while(!a.empty() && a.top() != '(')
                {
                    b.push(a.top());
                    a.pop();
                }
                a.pop();
                if(!a.empty() && a.top() == '-')
                {
                    while(!b.empty())
                    {
                        if(b.top() == '+')
                        {
                            a.push('-');
                            b.pop();
                        }
                        else if(b.top() == '-')
                        {
                            a.push('+');
                            b.pop();
                        }
                        else{
                            a.push(b.top());
                            b.pop();
                        }
                    }
                }
                else{
                    while(!b.empty())
                    {
                        a.push(b.top());
                        b.pop();
                    }
                }
            }
        }
        string res = "";
        while(!a.empty())
        {
            res = a.top() + res;
            a.pop();
        }
        return res;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        string s1;
        cin >> s1;
        string res = chuanhoa(s);
        string res1 = chuanhoa(s1);
        if(res == res1)
        {
            cout << "YES";
        }
        else cout << "NO";
        cout << endl;
    }
    return 0;
}
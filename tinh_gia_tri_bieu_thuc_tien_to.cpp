#include<iostream>
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
        stack<int>v = stack<int>();
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                int a = int(v.top());
                v.pop();
                int b = int(v.top());
                v.pop();
                if(s[i] == '+')
                {
                    v.push(a + b);
                }
                else if(s[i] == '-')
                {
                    v.push(a - b);
                }
                else if(s[i] == '*')
                {
                    v.push(a * b);
                }
                else if(s[i] == '/')
                {
                    v.push(a / b);
                }
            }
            else{
                v.push(int(s[i] - '0'));
            }
        }
        cout << v.top() << endl;
    }
    return 0;
}
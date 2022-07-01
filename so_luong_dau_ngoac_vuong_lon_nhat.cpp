#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int t;
    t = 1;
    while(t--)
    {
        string s;
        getline(cin, s);
        stack<char>st=stack<char>();
        int res = 0;
        int Max = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '[' || s[i] == '(')
            {
                st.push(s[i]);
            }
            else{
                if(s[i] == ')')
                {
                    if(!st.empty() && st.top() == '(') 
                    {
                        st.pop();
                    }
                    else{
                        res = 0;
                    }
                }
                else if(s[i] == ']')
                {
                    if(!st.empty() && st.top() == '[')
                    {
                        res++;
                        if(res > Max)
                        {
                            Max = res;
                        }
                        st.pop();
                    }
                    else{
                        res = 0;
                    }
                }
            }
        }
        cout << Max << endl;
    }
    return 0;
}
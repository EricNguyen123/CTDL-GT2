#include<iostream>
#include<string>
#include<stack>
using namespace std;
string KiemTra(string s)
{
        stack<char>st=stack<char>();
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '[' || s[i] == '(')
            {
                st.push(s[i]);
                //cout << st.top();
            }
            if(s[i] == ')')
            {
                if(!st.empty() && st.top() == '(') st.pop();
                else{
                    return "NO";
                }
            }
            else if(s[i] == ']')
            {
                if(!st.empty() && st.top() == '[') st.pop();
                else{
                    return "NO";
                }
            }
        }
        if(st.empty()){
            return "YES";
        }
        else{
            return "NO";
        }
}
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin, s);
        cout << KiemTra(s) << endl;
    }
    return 0;
}
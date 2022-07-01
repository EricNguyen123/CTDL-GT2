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
        stack<char>st = stack<char>();
        string so, chu, res = "";
        for(int i = 0; i < s.size(); i++)
        {
            so = chu = "";
            if(s[i] != ']') st.push(s[i]);
            else{
                while(!st.empty() && st.top() != '[')
                {
                    chu = chu + st.top();
                    st.pop();
                }
                //cout << chu <<" ";
                if(!st.empty())
                {
                    st.pop();
                }
                //cout << st.top() << " ";
                while(!st.empty() && isdigit(st.top()))
                {
                    so = st.top() + so;
                    st.pop();
                }
                if(so == "")
                {
                    so = "1";
                }
                
                int n = stoi(so);
                string a = "";
                for(int i = 0; i < n; i++)
                {
                    a = a + chu;
                }
                //cout << a << " ";
                for(int i = a.size() - 1; i >= 0; i--)
                {
                    st.push(a[i]);
                }

            }
        }
        //cout << st.size() << " ";
        while(!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        cout << res << endl;
    }
    return 0;
}
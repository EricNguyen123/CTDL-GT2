#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        stack<int>v = stack<int>();
        v.push(n - 1);
        int b[n];
        b[n - 1] = -1;
        for(int i = n - 2; i >= 0; i--)
        {
            if(!v.empty() && a[i] < a[v.top()])
            {
                b[i] = v.top();
                v.push(i);
            }
            else{
                while(!v.empty() && a[i] >= a[v.top()]) v.pop();
                if(!v.empty())
                {
                    b[i] = v.top();
                    v.push(i);
                }
                else{
                    b[i] = -1;
                    v.push(i);
                }
            }
        }
        stack<int>u = stack<int>();
        u.push(n - 1);
        int c[n];
        c[n - 1] = -1;
        for(int i = n - 2; i >= 0; i--)
        {
            if(!u.empty() && a[i] > a[u.top()])
            {
                c[i] = u.top();
                u.push(i);
            }
            else{
                while(!u.empty() && a[i] <= a[u.top()]) u.pop();
                if(!u.empty())
                {
                    c[i] = u.top();
                    u.push(i);
                }
                else{
                    c[i] = -1;
                    u.push(i);
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(b[i] != -1 && c[b[i]] != -1) cout << a[c[b[i]]] << " ";
            else{
                cout << -1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
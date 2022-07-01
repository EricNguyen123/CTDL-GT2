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
        v.push(a[n - 1]);
        int b[n];
        b[n - 1] = -1;
        for(int i = n - 2; i >= 0; i--)
        {
            if(!v.empty() && a[i] < v.top())
            {
                b[i] = v.top();
                v.push(a[i]);
            }
            else{
                while(!v.empty() && a[i] >= v.top()) v.pop();
                if(!v.empty())
                {
                    b[i] = v.top();
                    v.push(a[i]);
                }
                else{
                    b[i] = -1;
                    v.push(a[i]);
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
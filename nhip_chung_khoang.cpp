#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        stack<int>v=stack<int>();
        int b[n];
        for(int i = 0; i < n; i++)
        {
            while(!v.empty() && a[v.top()] <= a[i]) v.pop();
            if(v.empty()) b[i] = -1;
            else b[i] = v.top();
            v.push(i);
        }
        for(int i = 0; i < n; i++)
        {
            cout << i - b[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
#include<iostream>
#include<algorithm>
#include<stdbool.h>
#include<string>
#include<queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int m = s.size();
        int a[30] = {};
        for(int i = 0; i < m; i++)
        {
            a[int(s[i] - 'A')]++;
        }
        sort(a, a + 30);
        priority_queue<int> v;
        for(int i = 0; i < 30; i++)
        {
            if(a[i] != 0)
            {
                v.push(a[i]);
            }
        }
        while(n > 0 && v.empty() == false)
        {
            int x = v.top();
            v.pop();
            x--;
            v.push(x);
            n--;
        }
        if(v.empty())
        {
            cout << 0 << endl;
        }
        else{
            long long sum = 0;
            while(!v.empty())
            {
                int x = v.top();
                v.pop();
                sum += x * x;
            }
            cout << sum << endl;
        }
    }
    return 0;
}
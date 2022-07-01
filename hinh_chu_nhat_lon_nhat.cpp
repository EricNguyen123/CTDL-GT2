#include<iostream>
#include<deque>
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
        long long a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        deque<int>v = deque<int>();
        long long Max = a[0];
        v.push_back(0);
        for(int i = 1; i < n; i++)
        {
            while(!v.empty() && a[i] <= a[v.back()]) v.pop_back(); 
            v.push_back(i);
            deque<int>q=deque<int>();
            int b = 0;
            while(!v.empty())
            {
                Max = max(Max, a[v.front()] * (v.back() - b + 1));
                b = v.front() + 1;
                q.push_back(v.front());
                v.pop_front();
            }
            while(!q.empty())
            {
                v.push_back(q.front());
                q.pop_front();
            }
        }
        cout << Max << endl;
    }
    return 0;
}
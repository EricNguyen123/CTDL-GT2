#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>res(1e5, 0);
int check(int a, int b)
{
    while(a > 0)
    {
        if(a % 10 == b) return 0;
        a /= 10;
    }
    return 1;
}
void xuly()
{
    queue<int>q=queue<int>();
    for(int i = 1; i <= 5; i++) 
    {
        q.push(i);
        res[i] = 1;
    }
    while(q.back() <= 1e5)
    {
        int fr = q.front();
        q.pop();
        if(check(fr, 0) == 1) 
        {
            q.push(fr * 10);
            res[fr * 10] = 1;
        }
        for(int i = 1; i <= 5; i++)
        {
            if(check(fr, i) == 1)
            {
                int m = fr * 10 + i;
                q.push(m);
                res[m] = 1; 
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    xuly();
    while(t--)
    {
        int l, r;
        cin >> l >> r;
        int d = 0;
        for(int i = l; i <= r; i++)
        {
            d += res[i];
        }
        cout << d << endl;
    }
    return 0;
}
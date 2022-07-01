#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;
vector<int>res;
map<int,bool>a;
priority_queue<int, vector<int>, greater<int> >b;
void khoitao()
{
    b.push(1);
    while(res.size() <= 1e4)
    {
        int tg = b.top();
        b.pop();
        res.push_back(tg);
        if(!a[tg << 1])
        {
            a[tg << 1] = true;
            b.push(tg << 1);
        }
        if(!a[tg * 3])
        {
            a[tg * 3] = true;
            b.push(tg * 3);
        }
        if(!a[tg * 5])
        {
            a[tg * 5] = true;
            b.push(tg * 5);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    khoitao();
    while(t--)
    {
        int n;
        cin >> n;
        cout << res[n - 1] << endl;
    }
    return 0;
}
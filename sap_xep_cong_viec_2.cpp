#include<iostream>
#include<algorithm>
#include<stdbool.h>
#include<bitset>
#define M 1005
using namespace std;
struct  CV
{
    int deadline;
    int profit;
};

bool check(CV a, CV b)
{
    return a.profit > b.profit;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        int x;
        int count = 0;
        int Profit = 0;
        cin >> n;
        CV v[n];
        for(int i = 0; i < n; i++)
        {
            cin >> x >> v[i].deadline >> v[i].profit;
        }
        sort(v, v + n, check);
        bitset <M> bs;
        for(int i = 0; i < n; i++)
        {
            while(bs[v[i].deadline] && v[i].deadline)
            {
                v[i].deadline--;
            }
            if(!bs[v[i].deadline] && v[i].deadline)
            {
                count++;
                Profit += v[i].profit;
                bs[v[i].deadline] = 1;
            }
        }
        cout << count << " " << Profit << endl;
    }
    return 0;
}
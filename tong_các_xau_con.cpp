#include<iostream>
#include<string>
using namespace std;
string s;
int k;
long long sum;
char x[20];
void tinh(int i)
{
    long long t = 0;
    for(int j = k; j <= i; j++)
    {
        t = t * 10 + x[j] - '0';
    }
    sum += t;
}
void xuly(int i)
{
    for(int j = i - 1; j < s.size(); j++)
    {
        x[i] = s[j];
        tinh(i);
        xuly(i + 1);
        j = s.size() - 1;
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        sum = 0;
        for(k = 1; k <= s.size(); k++)
        {
            xuly(k);
        }
        cout << sum << endl;
    }
    return 0;
}
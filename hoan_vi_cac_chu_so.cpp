#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int n, k;
string s[10];
int x[10];
bool y[10];
int z[10];
long Min;
long chuyendoi(string a)
{
    long b = 0;
    for(int i = 0; i < k; i++)
    {
        b = b * 10 + int(a[i] - '0');
    }
    return b; 
}
string kqhoanvi(string a)
{
    string b = ""; 
    for(int i = 1; i <= k; i++)
    {
        b += char(a[x[i] - 1]);
    }
    return b; 
}
void xetduyet()
{
    long a = INT_MIN;
    long b = INT_MAX;
    for(int i = 1; i <= n; i++)
    {
        a = max(a, chuyendoi(kqhoanvi(s[i])));
        b = min(b, chuyendoi(kqhoanvi(s[i])));
    }
    Min = min(Min, a - b);
}

void xuly(int i)
{
    for(int j = 1; j <= k; j++)
    {
        if(y[j] == false)
        {
            x[i] = j;
            y[j] = true;
            if(i == k)
            {
                xetduyet();
            }
            else{
                xuly(i + 1);
            }
            y[j] = false;
        }
    }
}
int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for(int i = 1; i <= k; i++)
    {
        y[i] = false;
    }
    Min = INT_MAX;
    z[0] = 0;
    xuly(1);
    cout << Min << endl;
    return 0;
}
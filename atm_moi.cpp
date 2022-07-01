#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#define e 1000000007
using namespace std;
unsigned long long w;
int c;
int y[1000000];
long Min;
long Count;
unsigned long long gh;
vector < unsigned long long >a;
vector < unsigned long long >x;
vector < unsigned long long >z;
void khoi_tao()
{
    int j = 0;
    for(int i = 0; i < 16; i++)
    {
        unsigned long long b;
        b = 1000 * pow(10, i);
        a.push_back(b);
       
        b = 2000 * pow(10, i);
        a.push_back(b);
        
        b = 3000 * pow(10, i);
        a.push_back(b);

        b = 5000 * pow(10, i);
        a.push_back(b);
    }
    y[0] = 0;
}
void xu_ly(long i, int m)
{
    for(int j = m; j >= 0; j--)
    {
        while(a[j] <= w)
        {
            w -= a[j];
            x.push_back(a[j]);
            Min++;
        }      
    }
    if(w == 0)
    {
        Count = 1;
    }
}
bool search(int l, int r, unsigned long long v, vector < unsigned long long >o)
{
    int mid = l + (r - l) / 2;
    while(l <= r)
    {
        if(o[mid] == v)
        {
            return true;
        }
        else if(o[mid] < v)
        {
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
        mid = l + (r - l) / 2;
    }
    return false;
}
void kiemtra(int k)
{
    unsigned long long sum = 0;
    
    for(int i = 1; i <= k; i++)
    {
        sum += x[y[i] - 1];
        z.push_back(x[y[i] - 1]);
    }
    if(sum % k == 0)
    {
        if(search(0, c, sum / k, a) == true && search(0, z.size() - 1, sum / k, z) == false)
        {
            z.push_back(sum / k);
            Count++;
        }
    }
}
void tohop(int i, int k)
{
    for(int j = y[i - 1] + 1; j <= Min - k + i; j++)
    {
        y[i] = j;
        if(i == k)
        {
            kiemtra(k);
        }
        else{
            tohop(i + 1, k);
        }
    }
}
void dem()
{
    for(int i = 2; i <= Min; i++)
    {
        tohop(1, i);
    }
}
int main()
{
    khoi_tao();
    int t;
    cin >> t;
    while (t--)
    {
        x.clear();
        z.clear();
        cin >> w;
        cin >> c; 
        c++;
        c *= 4;
        c--;
        Min = 0;
        Count = 0;
        xu_ly(1, c);
        dem();
        if(Count == 0) 
        {
            cout << 0 << endl;
        }
        else{
            cout << Min << " " << Count << endl;
        }
        
    }
    
    return 0;
}

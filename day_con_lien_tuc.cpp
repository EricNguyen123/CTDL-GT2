#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int a[30];
vector <int> b;
vector <string> kq;
string chuyendoi(int i)
{
    string s = "";
    while(i > 0)
    {
        int d = i % 10;
        s = char(d + 48) + s;
        i /= 10; 
    }
    return s;
}
void result()
{
    string s = "";
    for(int i = 0; i < b.size(); i++)
    {
        string v = chuyendoi(b[i]);
        s += v;
        s += " ";
    }
    kq.push_back(s);
}
void xu_ly(int i)
{
    for(int j = i + 1; j <= n; j++)
    {
        if(a[j] > a[i])
        {
            b.push_back(a[j]);
            if(b.size() > 1) result();
            xu_ly(j);
            b.pop_back();
        }
    }

}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[0] = 0;
    xu_ly(0);
    sort(kq.begin(), kq.end());
    for(int i = 0; i < kq.size(); i++)
    {
        cout << kq[i] << endl;
    }
    return 0;
}
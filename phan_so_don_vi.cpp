#include<iostream>
#include<algorithm>
#include<stdbool.h>
using namespace std;
struct PhanSo
{
    long long a;
    long long b;
};
void In(PhanSo x)
{
    cout << x.a << "/" << x.b;
}
long long UCLN(long long a, long long b)
{
    while(b != 0)
    {
        long long tg = a % b;
        a = b;
        b = tg;
    }
    return a;
}
PhanSo Rutgon(PhanSo x)
{
    long long g = UCLN(x.a, x.b);
    x.a /= g;
    x.b /= g;
    return x;
}
PhanSo Quydong(PhanSo x, long long y)
{
    x.a *= y;
    x.b *= y;
    return x;
}
bool Sosanh(PhanSo x, PhanSo y)
{
    if(x.b != y.b)
    {
        long long tg = x.b;
        x = Quydong(x, y.b);
        y = Quydong(y, tg);
    }
    if(x.a >= y.a)
    {
        return true;
    }
    return false;
}
PhanSo Tru(PhanSo x, PhanSo y)
{
    if(x.b != y.b)
    {
        long long tg = x.b;
        x = Quydong(x, y.b);
        y = Quydong(y, tg);
    }
    PhanSo z;
    z.a = x.a - y.a;
    z.b = x.b;
    z = Rutgon(z);
    return z;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        PhanSo x;
        cin >> x.a >> x.b;
        if(x.a == 1)
        {
            In(x);
            cout << endl;
            continue;
        }
        PhanSo z;
        z.a = 1;
        z.b = 2;
        while(x.a > 0)
        {
            while(Sosanh(x, z) == false)
            {
                z.b++;
            }
            while(Sosanh(x, z))
            {
                x = Tru(x, z);
               // In(x);
                In(z);
                if(x.a != 0)
                {
                    cout << " + ";
                }
                //break;
            }
            if(x.a == 1)
            {
                In(x);
                //cout << endl;
                break;
            }
        }
        cout << endl;
    }
    return 0;
}
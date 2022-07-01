#include<iostream>
using namespace std;
long long MinA(long long a)
{
    long long rs = 0;
    long long ex = 1;
    while(a > 0)
    {
        long long m = a % 10;
        if(m == 6)
        {
            m = 5;
        }
        rs += m * ex;
        ex *= 10;
        a /= 10;
    }
    return rs;
}
long long MaxA(long long a)
{
    long long rs = 0;
    long long ex = 1;
    while(a > 0)
    {
        long long m = a % 10;
        if(m == 5)
        {
            m = 6;
        }
        rs += m * ex;
        ex *= 10;
        a /= 10;
    }
    return rs;
}
int main()
{
    long long a, b;
    cin >> a >> b;
    long long Min, Max;
    Min = MinA(a) + MinA(b);
    Max = MaxA(a) + MaxA(b);
    cout << Min << " " << Max << endl;
}
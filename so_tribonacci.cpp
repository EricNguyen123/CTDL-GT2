#include<iostream>
using namespace std;
const long long mod = 1e15 + 7;
struct Matrix
{
    int x, y;
    long long v[4][4];
};
Matrix operator *(Matrix a, Matrix b)
{
    Matrix c = {a.x, b.y}; 
    for(int i = 0; i < a.x; i++)
    {
        for(int j = 0; j < b.y; j++)
        {
            c.v[i][j] = 0;
            for(int l = 0; l < a.y; l++)
            {
                c.v[i][j] += ((a.v[i][l] % mod) * (b.v[l][j] % mod)) % mod;
                c.v[i][j] %= mod;
            }
        }
    }
    return c; 
}
Matrix luy_thua(Matrix a, long long n)
{
    if(n == 1) return a;
    Matrix p = luy_thua(a, n / 2);
    p = (p * p);
    if(n % 2 != 0)
    {
        p = p * a;
    }
    return p;
}
int main()
 {
    int f[5] = {0}, t[5];
    for(int i = 1; i <= 3; i++)
    {
        t[i] = i;
    }
    for(int i = 1; i <= 3; i++)
    {
        f[i] = t[i] + f[i - 1]; 
    }
    Matrix a, x;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            x.v[i][j] = 0;
        }
    }
    a.x = 4;
    a.y = 1;
    a.v[0][0] = f[3];
    a.v[1][0] = t[3];
    a.v[2][0] = t[2];
    a.v[3][0] = t[1];
    x.x = x.y = 4;
    x.v[0][0] = x.v[0][1] = x.v[0][2] = x.v[0][3] = 1;
    x.v[1][1] = x.v[1][2] = x.v[1][3] = 1;
    x.v[2][1] = x.v[3][2] = 1;
    int tt;
    cin >> tt;
    while(tt--)
    {
        long long n;
        cin >> n;
        if(n == 0) 
        {
            cout << 0 << endl;
            continue;
        }
        if(n <= 3)
        {
            cout << f[n] << endl;
            continue;
        }
        Matrix ans = luy_thua(x, n - 3) * a;
        cout << ans.v[0][0] % mod << endl;
    }
    return 0;
}
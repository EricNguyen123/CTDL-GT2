#include<iostream>
using namespace std;
int n;
int x[15];
int y[15];
int s[15];
void hoanviso(int i)
{
    for(int j = 1; j <= n; j++)
    {
        s[i] = j;
        if(i == n)
        {
            for(int l = 1; l <= n; l++)
            {
                cout << char(x[l] - 1 + 'A');
            }
                
            for(int l = 1; l <= n; l++)
            {
                cout << s[l];
            }
            cout << endl;
        }
        else{
            hoanviso(i + 1);
        }
    }
}
void hoanvichu(int i)
{
    for(int j = 1; j <= n; j++)
    {
        if(y[j] == 0)
        {
            y[j] = 1;
            x[i] = j;
            if(i == n)
            {
                hoanviso(1);
            }
            else{
                hoanvichu(i + 1);
            }
            y[j] = 0;
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < 15; i++)
    {
        y[i] = 0;
    }
    hoanvichu(1);
    return 0;
}
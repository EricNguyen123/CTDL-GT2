#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int s4;
        int s7;
        s7 = n / 7;
        while(s7 >= 0)
        {
            if((n - s7 * 7) % 4 == 0)
            {
                s4 = (n - s7 * 7) >> 2;
                break;
            }
            s7--;
        }
        if(s7 >=0)
        {
            while(s4--)
            {
                cout << 4;
            }
            while(s7--)
            {
                cout << 7;
            }
        }
        else{
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int d[1010] = {0};
        d[0] = d[1] = 1;
        if(s[0] == '0'){
            cout << 0 << endl;
            continue;
        } 
        for(int i = 2; i <= s.size(); i++)
        {
            if(s[i - 1] > '0') d[i] = d[i - 1];
            if(s[i - 2] == '1' or (s[i - 2] == '2' && s[i - 1] < '7')) d[i] += d[i - 2];
        }
        cout << d[s.size()] << endl;
    }
    return 0;
}
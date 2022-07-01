#include<iostream>
#include<map>
#include<set>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        map<char,int>a;
        for(int i = 0; i < s.size(); i++)
        {
            a[s[i]]++;
        }
        set<int,greater<int> >b;
        for(int i = 0; i < s.size(); i++)
        {
            b.insert(a[s[i]]);
        }
        set<int>::iterator it = b.begin();
        if(s.size() - *it >= *it - 1)
        {
            cout << 1 << endl;
        }
        else{
            cout<< -1 << endl;
        }
    }
    return 0;
}
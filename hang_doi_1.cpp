#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int m, p;
        queue<int>v=queue<int>();
        while(n--)
        {
            cin >> m;
            if(m == 3)
            {
                cin >> p;
                v.push(p);
            } 
            else if(m == 1)
            {
                cout << v.size() << endl;
            }
            else if(m == 2)
            {
                if(v.empty()) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
            else if(m == 4)
            {
                if(!v.empty()) v.pop();
            }
            else if(m == 5)
            {
                if(v.empty()) cout << "-1" << endl;
                else cout << v.front() << endl;
            }
            else if(m == 6)
            {
                if(v.empty()) cout << "-1" << endl;
                else cout << v.back() << endl;
            }
        }
    }
    return 0;
}
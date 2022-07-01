#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    queue<int>v=queue<int>();
    while(n--)
    {
        string s;
        int m;
        cin >> s;
        if(s == "PUSH")
        {
            cin >> m;
            v.push(m);
        }
        else if(s == "POP") 
        {
            if(!v.empty()) v.pop();
        }
        else if(s == "PRINTFRONT") 
        {
            if(v.empty()) cout << "NONE" << endl;
            else cout << v.front() << endl;
        }
    }
    return 0;
}
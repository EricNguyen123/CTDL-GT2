#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int t;
    cin >> t;
    stack<int>v = stack<int>();
    while(t--)
    {
        string s;
        int a;
        cin >> s;
        if(s == "PUSH") cin >> a;
        if(s == "PUSH") v.push(a);
        else if(s == "POP" && !v.empty()) v.pop();
        else if(s == "PRINT")
        {
            if(v.empty()) {
                cout << "NONE" << endl;
                continue;
            }
            cout << v.top() << endl;
        }
    }
    return 0;
}
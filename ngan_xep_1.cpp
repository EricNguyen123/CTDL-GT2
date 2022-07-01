#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int>v = stack<int>();
    while(cin)
    {
        string s;
        int a;
        cin >> s;
        if(s == "push") cin >> a;
        if(s == "push") v.push(a);
        else if(s == "pop") v.pop();
        else if(s == "show")
        {
            if(v.empty()) {
                cout << "empty" << endl;
                continue;
            }
            stack<int>x;
            while(!v.empty())
            {
                x.push(v.top());
                v.pop();
            }
            while(!x.empty())
            {
                cout << x.top() << " ";
                v.push(x.top());
                x.pop();
            }
            cout << endl;
        }
    }
    return 0;
}
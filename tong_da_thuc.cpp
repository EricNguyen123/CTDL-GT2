#include<iostream>
#include<stack>
#include<string>
using namespace std;
long long chuyenso(string a)
{
    long long b = 0;
    for(int i = 0; i < a.size(); i++)
    {
        b = b * 10 + int(a[i] - '0');
    }
    return b;
}
string chuyenchu(long long a)
{
    if(a == 0) return "0";
    string b = "";
    while(a > 0)
    {
        b = char(a % 10 + '0') + b;
        a /= 10;
    }
    return b;
}
string layBac(string a)
{
    string bac = "";
    int i = a.rfind("^");
    for(int j = i + 1; j < a.size(); j++)
    {
        bac = bac + a[j];
    }
    return bac;
}
string layHang(string a)
{
    string hang = "";
    int i = a.find("*");
    for(int j = 0; j < i; j++)
    {
        hang = hang + a[j];
    }
    return hang;
}
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        s1 = s1 + " + ";
        s2 = s2 + " + ";
        stack<string>st=stack<string>();
        int i = s1.find(" + ");
        int p = 0;
        while(i > -1)
        {
            string v = "";
            for(int j = p; j < i; j++)
            {
                v = v + s1[j];
            }
            st.push(v);
            p = i + 3;
            s1 = s1.replace(i, 3, "   ");
            i = s1.find(" + ");
        }
        i = s2.find(" + ");
        p = 0;
        while(i > -1)
        {
            string v = "";
            for(int j = p; j < i; j++)
            {
                v = v + s2[j];
            }
            string s = st.top();
            string bac1 = "", bac2 = "";
            bac1 = layBac(s);
            bac2 = layBac(v);
            long long x, y;
            x = chuyenso(bac1);
            y = chuyenso(bac2);
            stack<string>tg = stack<string>();
            while(!st.empty() && x < y)
            {
                tg.push(st.top());
                st.pop();
                bac1 = layBac(st.top());
                x = chuyenso(bac1);
            }
            if(x == y)
            {
                string hang1, hang2;
                hang1 = layHang(st.top());
                hang2 = layHang(v);
                long long a = chuyenso(hang1) + chuyenso(hang2);
                hang1 = chuyenchu(a);
                string p = "";
                p = p + hang1 + "*x^" + chuyenchu(x);
                st.pop();
                st.push(p);   
            }
            else{
                st.push(v);
            }
            while(!tg.empty())
            {
                st.push(tg.top());
                tg.pop();
            }
            p = i + 3;
            s2 = s2.replace(i, 3, "   ");
            i = s2.find(" + ");
        }
        string res = "";
        res = st.top() + res;
        st.pop();
        while(!st.empty())
        {
            res = st.top() + " + " + res;
            st.pop();
        }
        cout << res << endl;
    }
    return 0;
}
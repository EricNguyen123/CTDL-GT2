#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<int> >ds(2);
    for(int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string word;
        while(ss >> word)
        {
            int a = 0;
            for(int i = 0; i < word.size(); i++)
            {
                a = a * 10 + int(word[i] - '0');
            }
            if(a > i)
            {
                ds[0].push_back(i);
                ds[1].push_back(a);
            }
        }
    }
    for(int i = 0; i < ds[0].size(); i++)
    {
        cout << ds[0][i] << " " << ds[1][i] << endl;
    }
    return 0;
}
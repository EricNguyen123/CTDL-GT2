#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<int, int> length;
    int Max = -1;
    for(int i = 0; i < n; i++)
    {
        if(length.find(a[i] - 1) != length.end())
        {
            length[a[i]] = length[a[i] - 1] + 1;
        }
        else{
            length[a[i]] = 1;
        }
        Max = max(length[a[i]], Max);
    }
    cout << n - Max << endl;
}
#include<iostream>
#include<vector>
using namespace std;
int n;
string s;
int k;
vector <int> len;
void nhap()
{
	cin >> s >> n;
	len.push_back(0);
	int i = 0;
	int x = s.size();
	while(len[i] < n)
	{
		i++;
		len.push_back(x);
		x *= 2;
	}
	k = i;
}
int xu_ly(int i)
{
	if(i == 1)
	{
		return n;
	}
	if(n > len[i - 1])
	{
		n = n - 1 - len[i - 1];
		return xu_ly(i - 1);
	}
	return xu_ly(i - 1);
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		nhap();
		int v = xu_ly(k);
		cout << s[v - 1] << endl;
	}
	return 0;
}

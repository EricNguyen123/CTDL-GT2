#include<iostream>
using namespace std;
long long length[30];
int n;
long long k;
void len()
{
	length[1] = 1;
	for(int i = 2; i < 26; i++)
	{
		length[i] = 2 * length[i - 1] + 1;
	}
}
int xu_ly(int i, long long l)
{
	if(i == 1)
	{
		return i;
	}
	if(l == length[i - 1] + 1)
	{
		return i;
	}
	if(l > length[i - 1] + 1)
	{
		return xu_ly(i - 1, l - length[i - 1] - 1);
	}
	return xu_ly(i - 1, l);
}
int main()
{
	int t;
	cin >> t;
	len();
	while(t--)
	{
		cin >> n >> k;
		int x = xu_ly(n, k);
		string s = "";
		s += char(x - 1 + 'A');
		cout << s << endl;
	}
}

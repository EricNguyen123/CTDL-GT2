#include<iostream>
#include<stdbool.h>
#include<string>
using namespace std;
void in(int n, int x[], string s)
{
	for(int i = 1; i <= n; i++)
	{
		cout << s[x[i] - 1];
	}
	cout << " ";
}
void xuly(int i, int n, int x[], bool y[], string s)
{
	for(int j = 1; j <= n; j++)
	{
		if(y[j] == true)
		{
			x[i] = j;
			y[j] = false;
			if(i == n)
			{
				in(n, x, s);
			}
			else
			{
				xuly(i + 1, n, x, y, s);
			}
			y[j] = true;
		}
		
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int n;
		n = s.size();
		int *x = new int[n + 1];
		bool *y = new bool[n + 1];
		for(int i = 0; i <= n; i++)
		{
			y[i] = true;
		}
		xuly(1, n, x, y, s);
		cout << endl;
	}
	return 0;
}

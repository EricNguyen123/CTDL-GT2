#include<iostream>
#include<stdbool.h>
using namespace std;
void khoi_tao(int n, int x[])
{
	for(int i = 1; i <= n; i++)
	{
		x[i] = 0;
	}
}
int check(int n, int x[])
{
	for(int i = n; i >= 1; i--)
	{
		if(x[i] == 0)
		{
			return i;
		}
	}
	return 0;
}
void in(int n, int x[])
{
	for(int i = 1; i <= n; i++)
	{
		if(x[i] == 0)
		{
			cout << "A";
		}
		else
		{
			cout << "H";
		}
	}
	cout << endl;
}
bool kiem_tra(int n, int x[])
{
	if(x[1] == 1 && x[n] == 0)
	{
		for(int i = 1; i <= n; i++)
		{
			if(x[i] == x[i + 1] && x[i] == 1)
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
	
}
void xuly(int n, int x[])
{
	if(kiem_tra(n, x) == true)
	{
		in(n, x);
	}
	
	int i = check(n, x);
	while(i != 0)
	{
		x[i] = 1;
		for(int j = i + 1; j <= n; j++)
		{
			x[j] = 0;
		}
		if(kiem_tra(n, x) == true)
		{
			in(n, x);
		}
		i = check(n, x);
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int *x = new int[n + 1];
		khoi_tao(n, x);
		xuly(n, x);
	}
	return 0;
}

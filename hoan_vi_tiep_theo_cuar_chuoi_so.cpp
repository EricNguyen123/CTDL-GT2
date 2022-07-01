#include<iostream>
#include<string>
using namespace std;
int n;
int x[1005];
void tach_ky_tu(string s)
{
	n = s.size();
	for(int i = 0; i < n; i++)
	{
		x[i] = int(s[i] - '0');
	}
}
void xu_ly(string s, int o)
{
	tach_ky_tu(s);
	cout << o << " ";
	int m = -1;
	for(int i = n - 1; i >= 1; i--)
	{
		if(x[i] > x[i - 1])
		{
			m = i - 1;
			break;
		}
	}
	if(m != -1)
	{
		int min = 10;
		int j = -1;
		for(int i = n - 1; i > m; i--)
		{
			if(min > x[i] && x[i] > x[m])
			{
				min = x[i];
				j = i;
			}
		}
		if(j != -1)
		{
			int tg = x[j];
			x[j] = x[m];
			x[m] = tg;
		}
		m++;
		int k = n - 1;
		while(m < k)
		{
			int tg = x[m];
			x[m] = x[k];
			x[k] = tg;
			m++;
			k--;
		}
		for(int i = 0; i < n; i++)
		{
			cout << x[i];
		}
		cout << endl;
	}
	else
	{
		cout << "BIGGEST" << endl;
	}
	
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int o;
		cin >> o;
		string s;
		cin >> s;
		xu_ly(s, o);
	}
	return 0;
}

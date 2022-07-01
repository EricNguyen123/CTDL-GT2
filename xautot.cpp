#include<iostream>
#include<string>
#include<stdbool.h>
#include<vector>
using namespace std;
long long n;
string s;
long long N;
long long d;
long long l;
long long X[5];
vector<long long>st;
vector<long long>en;

void nhap()
{
	cin >> n;
	cin >> s;
	d = 0;
	X[0] = 0;
	l = 0;
}
bool kiem_tra_dx(long long b, long long e)
{
	while(b < e)
	{
		if(s[b] != s[e])
		{
			return false; 
		}
		e--;
		b++;
	}
	
	return true;
}
void tim_xau_dx(long long m)
{
	if(m == s.size())
	{
		return;
	}
	long long k = m + 1;
	for(long long j = k; j < s.size(); j++)
	{
		if(kiem_tra_dx(m, j) == true)
		{
			st.push_back(m);
			en.push_back(j);
			l++;
		}
		
	}
	tim_xau_dx(m + 1);
}
bool check(long long a, long long b, long long c, long long d)
{
	if((a < b && c < d) || (c == b))
	{
		return true;
	}
	return false;
}
void xu_ly()
{
	int m = 1;
	while(m <= N)
	{
		int h = m + 1;
		for(int i = h; i <= N; i++)
		{
			if(check(st[m - 1], st[i - 1], en[m - 1], en[i - 1]) == true)
			{
				d++;
			}
		}
		m++;
	}
}
void dem()
{
	N = l;
	xu_ly();
	cout << d + N << endl;
}
int main()
{
	nhap();
	tim_xau_dx(0);
	dem();
	return 0;
}

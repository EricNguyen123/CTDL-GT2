#include<iostream>
#include<string>
using namespace std;
int n;
string s[15];
int x[15];
int y[15][15];
int d = 0;
int MIN;
bool z[15];
void nhap()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		z[i] = false;
	}
	d = 0;
	MIN = 2000000;
}
int so_lan_lap(int a, int b)
{
	int dem = 0;
	for(int i = 0; i < s[a].size(); i++)
	{
		if(s[b].find(s[a][i]) != -1)
		{
			dem++;
		}
	}
	return dem;
}
void khoi_tao_ma_tran_ke()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			int dem = so_lan_lap(i , j);
			y[i][j] = dem;
			y[j][i] = dem;
		}
	
	}
}
void kiem_tra()
{
	int sum = 0;
	for(int i = 1; i < n; i++)
	{
		sum += y[x[i]][x[i + 1]];
	}
	if(sum < MIN)
	{
		MIN = sum;
	}
}
void xu_ly(int i)
{
	for(int j = 1; j <= n; j++)
	{
		if(z[j] == false)
		{
			x[i] = j;
			z[j] = true;
			if(i == n)
			{
				kiem_tra();
			}
			else
			{
				xu_ly(i + 1);
			}
			z[j] = false;
		}
	}
}
int main()
{
	nhap();
	khoi_tao_ma_tran_ke();
	xu_ly(1);
	cout << MIN << endl;
	return 0;
}


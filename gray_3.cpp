#include<iostream>
using namespace std;
int n;
int x[100];
int y[100];
string s;
void chuyen_data()
{
	n = s.size();
	for(int i = 1; i <= n; i++)
	{
		y[i] = int(s[i - 1] - '0'); 
	}
}
void gray_sang_nhi_phan()
{
	y[1] = x[1];
	for(int i = 2; i <= n; i++)
	{
		if((x[i] == 0 && y[i - 1] == 1) || (x[i] == 1 && y[i - 1] == 0))
		{
			y[i] = 1;
		}
		else if((x[i] == 1 && y[i - 1] == 1) || (x[i] == 0 && y[i - 1] == 0))
		{
			y[i] = 0;
		}
	}
}
void nhi_phan_sang_gray()
{
	x[1] = y[1];
	for(int i = 2; i <= n; i++)
	{
		if(y[i] == 1 && y[i - 1] == 1)
		{
			x[i] = 0;
		}
		else if(y[i] == 0 && y[i - 1] == 0)
		{
			x[i] = 0;
		}
		else if((y[i] == 1 && y[i - 1] == 0) || (y[i] == 0 && y[i - 1] == 1))
		{
			x[i] = 1;
		}
	}
}
void sinh_nhi_phan_ke_tiep()
{
	int i = n;
	for(i = n; i >= 1; i--)
	{
		if(y[i] == 0)
		{
			break;
		}
	}
	y[i] = 1;
	for(int j = i + 1; j <= n; j++)
	{
		y[j] = 0;
	}
}
void in()
{
	for(int i = 1; i <= n; i++)
	{
		cout << x[i];
	}
	cout << endl;
}
void xu_ly()
{
	chuyen_data();
//	gray_sang_nhi_phan();
//	sinh_nhi_phan_ke_tiep();
	nhi_phan_sang_gray();
	in();
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> s;
		xu_ly();
	}
	return 0;
}

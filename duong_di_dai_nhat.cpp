#include<iostream>
#include<algorithm>
#include<stdbool.h>
#define TRUE 1
#define FALSE 0
using namespace std;
struct canh
{
	int x;
	int y;
};
int n, m, u;
struct canh a[30];
int matrix[30][30];
void nhap()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> a[i].x >> a[i].y;
	}
}

void chuyen_doi_ma_tran_ke()
{
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}
	for(int i = 0; i < m; i++)
	{
		matrix[a[i].x][a[i].y] = 1;
		matrix[a[i].y][a[i].x] = 1;
	}
}
int Kiem_tra()
{
	int i, j, s, d;
	d = 0;
	for(i = 0; i < n; i++)
	{
		s = 0;
		for(j = 0; j < n; j++)
		{
			s += matrix[i][j];
		}
		if(s % 2 == 0)
		{
			d++;
			u = i;
		}
	}
	if(d != 2)
	{
		return FALSE;
	}
	return TRUE;
}
void DDEULER()
{
	int v, x, top,dCE;
	int stack[30], CE[30];
	top = 1;
	stack[top] = 0;
	dCE = 0;
	do
	{
		v = stack[top];
		x = 0;
		while(x < n && matrix[v][x] == 0)
		{
			x++;
	    }
			if(x > n)
			{
				dCE++;
				CE[dCE] = v;
				top--;
			}
			else
			{
				top++;
				stack[top] = x;
				matrix[v][x] = 0;
				matrix[x][v] = 0;
			}
		
	}
	while(top != 0);
	cout << dCE << endl;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		nhap();
		chuyen_doi_ma_tran_ke();
		if(Kiem_tra() == TRUE)
		{
			
		}
		DDEULER();
	}
	return 0;
}

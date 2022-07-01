#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int *x = new int[n];
		for(int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		int j = -1;
		for(int i = n - 1; i >= 1; i--)
		{
			if(x[i] > x[i - 1])
			{
				j = i - 1;
				break;
			}
		}
		int min = 10000;
		if(j != -1)
		{
			int jj = -1;
			for(int i = n - 1; i > j; i--)
			{
				if(min > x[i] )
				{
					min = x[i];
					jj = i;
				}
			}
			if(jj != -1)
			{
				int tg = x[jj];
				x[jj] = x[j];
				x[j] = tg;
				
			}
		}
	
		int m = n - 1;
		j++;
		while(j < m)
		{
			int tg = x[j];
		    x[j] = x[m];
		    x[m] = tg;
		    j++;
		    m--;
		}
		for(int i = 0; i < n; i++)
		{
			cout << x[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

#include<iostream>
using namespace std;
int n, s;
int sum;
int d;
int x[1006];
void nhap()
{
	cin >> s >> n;	
}

void in()
{
	for(int i = 1; i <= n; i++)
	{
		cout << x[i];
	}
	cout << endl;
}
void Min()
{
	sum = s;
	x[1] = 1;
	sum--;
	int c = 9 * (n - 1);
	while(sum > c && x[1] < 10)
	{
		x[1]++;
		sum--;
	}
	for(int i = 2; i <= n; i++)
	{
		c = 9 * (n - i);
        x[i] = 0;
		while(sum > c && x[i] < 10)
		{
			x[i]++;
			sum--;
		}
	}
	in();
	
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        nhap();
        if(n * 9 < s || 1 > s)
        {
            cout << -1 << endl;
        }
        else
        {
            Min();
        }
    }
	
	return 0;
}

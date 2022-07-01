#include<iostream>
#include<set>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n;
		cin >> m;
		int *a = new int[n];
		set <int> b;
		set <int> c;
		set <int> d;
		set <int> ::iterator it;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			c.insert(a[i]);
		}
		for(int i = 0; i < m; i++)
		{
			int x;
			cin >> x;
			b.insert(x);
			c.insert(x);
		}
		for( it = c.begin(); it != c.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
		for(int i = 0; i < n; i++)
		{
			it = b.find(a[i]);
			if(it != b.end())
			{
				d.insert(*it);
			}
		}
		for(it = d.begin(); it != d.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
}

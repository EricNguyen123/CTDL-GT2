#include<iostream>
#include<set>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long n, m, p;
		cin >> n >> m >> p;
		multiset <unsigned long long> a;
		multiset <unsigned long long> b;
		multiset <unsigned long long> c;
		multiset <unsigned long long> d;
		for(long i = 0; i < n; i++)
		{
			unsigned long long x;
			cin >> x;
			a.insert(x);
		}
		for(long i = 0; i < m; i++)
		{
			unsigned long long x;
			cin >> x;
			b.insert(x);
		}
		for(long i = 0; i < p; i++)
		{
			unsigned long long x;
			cin >> x;
			c.insert(x);
		}
		
		multiset <unsigned long long> ::iterator ib;
		multiset <unsigned long long> ::iterator ic;
		
		for(multiset <unsigned long long> ::iterator i = a.begin(); i != a.end(); i++)
		{
			ib = b.find(*i);
			ic = c.find(*i);
			if(ib != b.end() && ic != c.end())
			{
				d.insert(*i);
				b.erase(ib);
				c.erase(ic);
			}
		}
		
		if(d.empty() == true)
		{
			cout << "-1" << endl;
		}
		else
		{
			for(multiset <unsigned long long> ::iterator i = d.begin(); i != d.end(); i++)
			{
				cout << *i << " ";
			}
			cout << endl;
		}
		
	}
	return 0;
}

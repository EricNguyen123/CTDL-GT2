#include<iostream>
#include<vector>
using namespace std;

long long fibo(int n)
{
	if (n < 2)
	{
		return n;
	}
	
	return fibo(n - 1) + fibo(n - 2);
}

long long fibo1(int n)
{
	vector <long long> fi;
	fi.push_back(0);
	fi.push_back(1);
	for(int i = 2; i <= n; i++)
	{
		long long x = fi[i - 1] + fi[i - 2];
		fi.push_back(x);
	}
	return fi[n];
}

unsigned long long fibo2(int n)
{
	
	if(n < 2)
	{
		return n;
	}
	unsigned long long a = 0, b = 1, c;
	for(int i = 2; i <= n; i++)
	{
	    c = a + b;
	    a = b;
	    b = c;
	}
	return c; 
}

int main()
{
	
//	cout << fibo(39) << endl;
//	cout << fibo1(n) << endl;
	cout << fibo2(93) << endl;
	return 0;
}
